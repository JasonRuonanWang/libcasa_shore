#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/ArrayMath.h>
#include <casacore/casa/Arrays/IPosition.h>
#include <casacore/casa/Containers/Record.h>
#include <casacore/casa/Utilities/Compare.h>
#include <casacore/casa/Exceptions/Error.h>

extern "C"{
#include <shoreClient.h>
}

namespace casacore{

    class SetupNewTable;
    class DataManager;
    class TableDesc;

    class ColumnDescSet{
    };
    class BaseColumnDesc{
        public:
            BaseColumnDesc(){}
            int dataType(){return 0;}
            void handleRemove (ColumnDescSet &);
            void handleRename (ColumnDescSet &, const String&);
            void renameAction (const String &newName, const String &oldName);
            void handleAdd (ColumnDescSet &cds);
            const TableDesc * tableDesc () const;
            TableDesc * tableDesc ();
            void checkRename (const ColumnDescSet &cds, const String &newName) const;
            void checkAdd (const ColumnDescSet &cds) const;
    };

    class TableRecord {
        public:
            enum RecordType{
                Variable
            };
            const bool isDefined(string)const{return true;}
            void removeField(string){}
            const int asInt(string)const{return 0;}
            const string asString(string)const{return (const string)"";}
            void defineTable (const RecordFieldId &, const Table &value, RecordType type=Variable){}
            void define(string, string){}
    };
    class ColumnDesc{
        public:
            bool isScalar()const{return true;}
            enum Option {Direct,Undefined,FixedShape};
            DataType dataType()const{return TpString;}
            string col_name;
            string name(){return col_name;}
            const string dataManagerType()const{return "";}
            const string dataManagerGroup()const{return "";}
            void setShape(IPosition){}
            TableRecord & rwKeywordSet(){return tmp;}

            TableRecord tmp;
    };

    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(){}
            TableDesc(const String &type, TDOption=Old);
            TableDesc(const String& type, const String& version, TDOption = Old){}
            void defineHypercolumn(const String & hypercolumnName, uInt ndim, const Vector< String > & dataColumnNames){}
            void addColumn (BaseColumnDesc column){}
            string comment(){string tmp; return tmp;}
            Vector<String> columnNames() const{Vector<String> tmp; return tmp;}
            uInt ncolumn() const {return 0;}
            BaseColumnDesc columnDesc(uInt) const{BaseColumnDesc tmp; return tmp;}
            bool isColumn(String) const {return true;}
            const ColumnDesc & columnDesc(const String &name) const {return col_desc;}
            inline const ColumnDesc& operator[] (const String& name) const { return col_desc; }
            ColumnDesc & rwColumnDesc (const String &name){return col_desc;}
            ColumnDesc col_desc;
    };




    typedef DataManager *(* DataManagerCtor )(const String &dataManagerType, const Record &spec);
    class DataManager{
        public:
            static void registerCtor(string,DataManagerCtor){}
            static DataManager* makeObject(const String&, const Record&){return 0;}
    };

    class TableLock{
        public:
            enum LockOption{
                PermanentLocking,
                PermanentLockingWait,
                AutoLocking,
                UserLocking,
                AutoNoReadLocking,
                UserNoReadLocking,
                NoLocking,
                DefaultLocking
            };
            TableLock(LockOption option=DefaultLocking){}
    };

    class Table {
        public:
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            enum EndianFormat {LittleEndian, LocalEndian};
            Table(SetupNewTable &newtab, uInt nrrows = 0, bool a=true, EndianFormat b=LocalEndian);
            Table(string,TableOption){}
            Table(string);
            Table(){}
            const uInt nrow()const{return 0;}
            void addRow(){}
            void flush(){}
            EndianFormat endianFormat(){return LocalEndian;}
            void removeRow(uInt){}
            void removeRow(Vector<uInt>){}
            const TableDesc tableDesc() const{TableDesc *tmp = new TableDesc(); return *tmp;}
            void removeColumn(string){}
            void addColumn (BaseColumnDesc column){}
            void addColumn (TableDesc, DataManager){}
            string doid;
            bool isColumnWritable(string){return true;}
            void renameColumn(string,string){}
            bool isWritable()const{return true;}
            void addRow(int){}
            const TableRecord & keywordSet()const{TableRecord tmp; return tab_rec;}
            TableRecord & rwKeywordSet(){TableRecord tmp; return tab_rec;}
            TableDesc actualTableDesc()const{return tab_desc;}
            static bool isReadable(const string&){return true;}
            const TableLock & lockOptions()const{return tab_lock;}
            Block<String> getPartNames(Bool recursive = False)const{Block<String> tmp; return tmp;}

            TableRecord tab_rec;
            TableDesc tab_desc;
            TableLock tab_lock;

    };

    class TableColumn{
        public:
            TableColumn(Table const&, String const&);
            TableColumn(){}
            String doid;
            String columnName;
            ColumnDesc col_desc;
            mutable int dtype;
            uInt nrow()const{return 0;}
            ColumnDesc &columnDesc(){return col_desc;}
            IPosition shape(){return tmp;}
            IPosition shape(int){return tmp;}
            IPosition tmp;
    };

    typedef TableColumn ROTableColumn;

    template<class T> class ScalarColumn : public TableColumn{
        public:
            void put(uInt rowid, T data){
                shapePtr[0]=1;
                shapePtr[1]=1;
                shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
            }
            void putColumn(Vector<T> data){
                shapePtr[0]=1;
                shapePtr[1]=1;
                IPosition shape = data.shape();
                Bool deleteIt;
                const T *dataPtr = data.getStorage (deleteIt);
                shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), 0, shape(0), shapePtr, TableColumn::dtype, dataPtr);
                data.freeStorage(dataPtr, deleteIt);
            }
            T get(uInt rowid){
                int err = shoreQuery(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), &rows, shapePtr, &dtype);
                if (err){
                    return 0;
                }
                T scalar;
                shoreGet(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, &scalar);
                return scalar;
            }
            Vector<T> getColumn()const{
                int dtype_tmp;
                unsigned int rows_tmp, shapePtr_tmp[11];
                int err = shoreQuery(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), &rows_tmp, shapePtr_tmp, &dtype_tmp);
                if (err){
                    return Vector<T>(0);
                }
                Bool deleteIt;
                Vector<T> scalar(rows_tmp);
                T *data = scalar.getStorage (deleteIt);
                shoreGet(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), 0, 0, data);
                scalar.putStorage (data, deleteIt);
                return scalar;
            }
            void get(uInt rowid, T& data){}
            ScalarColumn(Table const& tab, String const& name);
            ScalarColumn(){}
            void attach(casa::Table const&, casa::String const&){}
            T operator() (uInt rownr) {T value; get(rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            unsigned int shapePtr[11];
            unsigned int rows;
    };

    template<class T> class ArrayColumn : public TableColumn{
        public:
            void put(uInt rowid, ArrayColumn<T> data){
            }
            void put(uInt rowid, Array<T> data){
                shapePtr[0] = data.ndim();
                shape = data.shape();
                for (unsigned int i=0; i<shapePtr[0]; i++){
                    shapePtr[i+1] = shape[i];
                }
                bool deleteIt;
                const T *dataPtr = data.getStorage (deleteIt);
                shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, dataPtr);
                data.freeStorage(dataPtr, deleteIt);
            }
            void putColumn(Array<T> data){
                shapePtr[0] = data.ndim() - 1;
                shape = data.shape();
                for (unsigned int i=0; i<shapePtr[0]; i++){
                    shapePtr[i+1] = shape[i+1];
                }
                bool deleteIt;
                const T *dataPtr = data.getStorage (deleteIt);
                shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), 0, shape(0), shapePtr, TableColumn::dtype, dataPtr);
                data.freeStorage(dataPtr, deleteIt);
            }
            Array<T> get(uInt rowid){
                shoreQuery(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), &rows, shapePtr, &(TableColumn::dtype));
                IPosition shape_i(shapePtr[0]);
                for (int i=0; i<shapePtr[0]; i++){
                    shape_i[i] = shapePtr[i+1];
                }
                Bool deleteIt;
                Array<T> arr(shape_i);
                T *data = arr.getStorage (deleteIt);
                shoreGet(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, data);
                arr.putStorage (data, deleteIt);
                return arr;
            }
            Array<T> getColumn(){
                shoreQuery(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), &rows, shapePtr, &(TableColumn::dtype));
                IPosition shape_i(shapePtr[0]+1);
                shape_i[0] = rows;
                for (int i=1; i<shapePtr[0]+1; i++){
                    shape_i[i] = shapePtr[i];
                }
                Bool deleteIt;
                Array<T> arr(shape_i);
                T *data = arr.getStorage (deleteIt);
                shoreGet(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), 0, rows, data);
                arr.putStorage (data, deleteIt);
                return arr;
            }
            ArrayColumn(casa::Table const& tab, casa::String const& name);
            ArrayColumn(){}
            void attach(casa::Table const&, casa::String const&){}
            Array<T> operator() (uInt rownr) {Array<T> value; get (rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            void get(uInt,Array<T>){}
            void get(uInt,Array<T>,Bool){}
            void setShape(uInt,IPosition){}
            void putSlice(uInt rowid, Slicer, Array<T> data){}
            Array<T> getSlice(uInt, Slicer){Array<T> tmp; return tmp;}
            void getSlice(uInt, Slicer, Array<T>){}
            Array<T> getColumn(Slicer){Array<T> tmp; return tmp;}
            unsigned int shapePtr[11];
            unsigned int rows;
            IPosition shape;
    };

    template<class T> class ROScalarColumn: public ScalarColumn<T>{
        public:
            ROScalarColumn(casa::Table const& tab, casa::String const& name) :ScalarColumn<T> (tab, name){}
    };

    template<class T> class ROArrayColumn: public ArrayColumn<T>{
        public:
            ROArrayColumn(casa::Table const& tab, casa::String const& name) :ArrayColumn<T> (tab, name){}
    };

    template<class T> class ScalarColumnDesc : public BaseColumnDesc {
        public:
            ScalarColumnDesc(const String&){}
            ScalarColumnDesc(const String&, string){}
            void setMaxLength(int){}
            virtual bool isScalar(){return true;}
    };

    template<class T> class ArrayColumnDesc : public BaseColumnDesc {
        public:
            ArrayColumnDesc(const String&){}
            ArrayColumnDesc(const String&, int){}
            ArrayColumnDesc(const String&, IPosition, ColumnDesc::Option){}
            ArrayColumnDesc(const String&, int, ColumnDesc::Option){}
            ArrayColumnDesc(const String &name, const String &comment, Int ndim=-1, int options=0){}
            void setMaxLength(int){}
            virtual bool isScalar(){return false;}
    };


    class SetupNewTable {
        public:
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption);
            void bindAll(DataManager){}
            void bindColumn(string,DataManager){}
            void setShapeColumn(string, IPosition){}
            string doid;
    };

    class StManAipsIO: public DataManager{
    };

    class StandardStMan: public DataManager{
        public:
            StandardStMan (Int bucketSize=0, uInt cacheSize=1){}
            StandardStMan (const String &dataManagerName, Int bucketSize=0, uInt cacheSize=1){}
    };

    class IncrementalStMan: public DataManager{
        public:
            IncrementalStMan (uInt bucketSize=0, Bool checkBucketSize=True, uInt cacheSize=1){}
            IncrementalStMan (const String &dataManagerName, uInt bucketSize=0, Bool checkBucketSize=True, uInt cacheSize=1){}
    };

    class TSMShape{
        public:
            TSMShape(IPosition){}
    };

    class TSMOption{};

    class RODataManagerAccessor{
        public:
            RODataManagerAccessor(){}
            RODataManagerAccessor(Table,string){}
            void showCacheStatistics(std::ostream & )const{}
            void showBaseStatistics(std::ostream & )const{}
            void showIndexStatistics(std::ostream & )const{}
            void setCacheSize(int){}
            void clearCache(){}
    };

    class ROIncrementalStManAccessor : public RODataManagerAccessor{
        public:
            ROIncrementalStManAccessor(Table,string){}
    };

    class ROStandardStManAccessor : public RODataManagerAccessor{
        public:
            ROStandardStManAccessor(Table,string){}
    };


    class TableError : public AipsError {
    };

    class TableArrayConformanceError : public TableError {
    public:
        TableArrayConformanceError (const String& message,Category c=CONFORMANCE);
        ~TableArrayConformanceError () throw();
    };

    class TableInvOper : public TableError {
    public:
        TableInvOper (Category c=INVALID_ARGUMENT);
        TableInvOper (const String& message,Category c=INVALID_ARGUMENT);
        ~TableInvOper () throw();
    };

    class ROTableRow{};
    class ROTiledStManAccessor{
        public:
            ROTiledStManAccessor(Table&, string&){}
            unsigned int nhypercubes(){return 0;}
            const IPosition& getTileShape(int hypercube)const{return tmp;}
            IPosition tmp;

    };
    class DataManagerColumn{};
    class TiledShapeStMan : public DataManager{
        public:
            TiledShapeStMan (const String &hypercolumnName, const IPosition &defaultTileShape, uInt maximumCacheSize=0){}
    };

    class TiledColumnStMan : public DataManager{
        public:
            TiledColumnStMan (const String &hypercolumnName, const Record &spec){}
            TiledColumnStMan (const String &hypercolumnName, const IPosition &tileShape, uInt maximumCacheSize=0){}
    };

}

#endif
