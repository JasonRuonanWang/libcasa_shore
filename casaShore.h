#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/IPosition.h>
#include <casacore/casa/Containers/Record.h>
#include <casacore/casa/Utilities/Compare.h>
#include <casacore/casa/Exceptions/Error.h>

namespace casacore{

    class SetupNewTable;
    class DataManager;
    class TableDesc;

    template<class T> class ScalarColumn{
        public:
            ScalarColumn(Table const& tab, String const& name);
            ScalarColumn(){}
            void put(uInt rowid, T data);
            void attach(casa::Table const&, casa::String const&){}
            T operator() (uInt rownr) {T value; get(rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            void putColumn(Vector<T> data){}
            void get(uInt,T&){}
            Vector<T> getColumn(){Vector<T> tmp; return tmp;}
            String doid;
            String columnName;
            int dtype;
    };

    template<class T> class ArrayColumn{
        public:
            ArrayColumn(casa::Table const&, casa::String const&);
            ArrayColumn(){}
            void attach(casa::Table const&, casa::String const&){}
            Array<T> operator() (uInt rownr) {Array<T> value; get (rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            void get(uInt,Array<T>){}
            void setShape(uInt,IPosition){}
            void put(uInt rowid, Array<T> data);
            void putSlice(uInt rowid, Slicer, Array<T> data){}
            Array<T> getSlice(uInt, Slicer){Array<T> tmp; return tmp;}
            void getSlice(uInt, Slicer, Array<T>){}
            Array<T> getColumn(){Array<T> tmp; return tmp;}
            Array<T> getColumn(Slicer){Array<T> tmp; return tmp;}
            String doid;
            String columnName;
            int dtype;
            unsigned int shapePtr[11];
            IPosition shape;
    };

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

    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(){}
            TableDesc(const String &type, TDOption=Old);
            TableDesc(const String& type, const String& version, TDOption = Old){}
            void addColumn (BaseColumnDesc column){}
            string comment(){string tmp; return tmp;}
            Vector<String> columnNames() const{Vector<String> tmp; return tmp;}
            uInt ncolumn() const {return 0;}
            BaseColumnDesc columnDesc(uInt) const{BaseColumnDesc tmp; return tmp;}
            bool isColumn(String) const {return true;}
    };

    class Table {
        public:
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            enum EndianFormat {LittleEndian, LocalEndian};
            Table(SetupNewTable &newtab, uInt nrrows = 0, bool a=true, EndianFormat b=LocalEndian);
            Table(string,TableOption){}
            Table(string){}
            Table(){}
            uInt nrow(){return 0;}
            void addRow(){}
            void flush(){}
            EndianFormat endianFormat(){return LocalEndian;}
            void removeRow(uInt){}
            void removeRow(Vector<uInt>){}
            const TableDesc tableDesc() const{TableDesc *tmp = new TableDesc(); return *tmp;}
            void removeColumn(string){}
            void addColumn (BaseColumnDesc column){}
            string doid;
    };

    template<class T> class ScalarColumnDesc : public BaseColumnDesc {
        public:
            ScalarColumnDesc(const String&){}
            ScalarColumnDesc(const String&, string){}
            void setMaxLength(int){}
    };

    class ColumnDesc{
        public:
            enum Option {Direct,Undefined,FixedShape};
    };

    template<class T> class ArrayColumnDesc : public BaseColumnDesc {
        public:
            ArrayColumnDesc(const String&){}
            ArrayColumnDesc(const String&, int){}
            ArrayColumnDesc(const String&, IPosition, ColumnDesc::Option){}
            ArrayColumnDesc(const String&, int, ColumnDesc::Option){}
            void setMaxLength(int){}
    };


    typedef DataManager *(* DataManagerCtor )(const String &dataManagerType, const Record &spec);
    class DataManager{
        public:
            static void registerCtor(string,DataManagerCtor){}
            static DataManager* makeObject(const String&, const Record&){return 0;}
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
            StandardStMan(int){}
            StandardStMan(string,int){}
    };

    class IncrementalStMan: public DataManager{
        public:
            IncrementalStMan(int,bool){}
            IncrementalStMan(string,int,bool){}
    };

    class TSMShape{
        public:
            TSMShape(IPosition){}
    };

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

}

#endif
