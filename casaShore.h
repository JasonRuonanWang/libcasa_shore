#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/IPosition.h>
#include <casacore/casa/Containers/Record.h>

namespace casacore{

    class SetupNewTable;
    class DataManager;

    template<class T> class ScalarColumn{
        public:
            ScalarColumn(casa::Table const&, casa::String const&){}
            T operator() (uInt rownr) {T value; get(rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            void put(uInt rowid, T data){}
            void putColumn(Vector<T> data){}
            void get(uInt,T&){}
            Vector<T> getColumn(){Vector<T> tmp; return tmp;}
    };

    template<class T> class ArrayColumn{
        public:
            ArrayColumn(casa::Table const&, casa::String const&){}
            Array<T> operator() (uInt rownr) {Array<T> value; get (rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            void get(uInt,Array<T>){}
            void setShape(uInt,IPosition){}
            void put(uInt rowid, Array<T> data){}
            void putSlice(uInt rowid, Slicer, Array<T> data){}
            Array<T> getSlice(uInt, Slicer){Array<T> tmp; return tmp;}
            void getSlice(uInt, Slicer, Array<T>){}
            Array<T> getColumn(){Array<T> tmp; return tmp;}
            Array<T> getColumn(Slicer){Array<T> tmp; return tmp;}
    };

    class Table {
        public:
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            enum EndianFormat {LittleEndian, LocalEndian};
            Table(SetupNewTable &newtab, uInt nrrows, bool a, EndianFormat b){}
            Table(SetupNewTable &newtab, uInt nrrows){}
            Table(SetupNewTable &newtab){}
            Table(string,TableOption){}
            Table(string){}
            Table(){}
            uInt nrow(){return 0;}
            void addRow(){}
            void flush(){}
            EndianFormat endianFormat(){return LocalEndian;}
            void removeRow(uInt){}
            void removeRow(Vector<uInt>){}
    };

    class BaseColumnDesc{
        public:
            BaseColumnDesc(){}
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

    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(const String& type, const String& version, TDOption = Old){}
            void addColumn (BaseColumnDesc column){}
            string comment(){string tmp; return tmp;}
    };

    typedef DataManager *(* DataManagerCtor )(const String &dataManagerType, const Record &spec);
    class DataManager{
        public:
            static void registerCtor(string,DataManagerCtor){}
    };

    class SetupNewTable {
        public:
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
            void bindAll(DataManager){}
            void bindColumn(string,DataManager){}
            void setShapeColumn(string, IPosition){}
    };

    class StManAipsIO: public DataManager{
    };

    class StandardStMan: public DataManager{
        public:
            StandardStMan(int){}
    };

    class IncrementalStMan: public DataManager{
        public:
            IncrementalStMan(int,bool){}
            IncrementalStMan(string,int,bool){}
            static DataManager* makeObject(const String&, const Record&){return 0;}
    };

    class TSMShape{
        public:
            TSMShape(IPosition){}
    };

    class ROIncrementalStManAccessor{
        public:
            ROIncrementalStManAccessor(Table,string){}
            void setCacheSize(int){}
            void showCacheStatistics(std::ostream & )const{}
            void clearCache(){}
    };
}

#endif
