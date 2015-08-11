#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/IPosition.h>

namespace casacore{

    class SetupNewTable;


    template<class T> class ScalarColumn{
        public:
            ScalarColumn(casa::Table const&, casa::String const&){}
            void put(uInt rowid, T data){}
            T operator() (uInt rownr) {T value; get(rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            Vector<T> getColumn(){Vector<T> tmp; return tmp;}
            void get(uInt,T&){}
    };

    template<class T> class ArrayColumn{
        public:
            ArrayColumn(casa::Table const&, casa::String const&){}
            void put(uInt rowid, Array<T> data){}
            Array<T> operator() (uInt rownr) {Array<T> value; get (rownr, value); return value;}
            bool isDefined(uInt){return true;}
            bool hasContent(uInt){return true;}
            Array<T> getSlice(uInt, Slicer){Array<T> tmp; return tmp;}
            Array<T> getColumn(){Array<T> tmp; return tmp;}
            Array<T> getColumn(Slicer){Array<T> tmp; return tmp;}
            void setShape(uInt,IPosition){}
            void get(uInt,Array<T>){}
    };



    // ******************************************************************
    // **************** below this line is all bullshit *****************
    class Table {
        public:
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            Table(SetupNewTable &newtab, uInt nrrows){}
            Table(string){}
            Table(string,TableOption){}
            uInt nrow(){return 0;}
    };

    // **************** another piece of bullshit  **********************
    class BaseColumnDesc{
        public:
            BaseColumnDesc(){}
    };

    // **************** another piece of bullshit  **********************
    template<class T> class ScalarColumnDesc : public BaseColumnDesc {
        public:
            ScalarColumnDesc(const String&){}
            ScalarColumnDesc(const String&, string){}
            void setMaxLength(int){}
    };

    // **************** another piece of bullshit  **********************
    class ColumnDesc{
        public:
            enum Option {Direct,Undefined,FixedShape};
    };

    // **************** another piece of bullshit  **********************
    template<class T> class ArrayColumnDesc : public BaseColumnDesc {
        public:
            ArrayColumnDesc(const String&){}
            ArrayColumnDesc(const String&, int){}
            ArrayColumnDesc(const String&, IPosition, ColumnDesc::Option){}
            ArrayColumnDesc(const String&, int, ColumnDesc::Option){}
            void setMaxLength(int){}
    };

    // **************** another piece of bullshit  **********************
    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(const String& type, const String& version, TDOption = Old){}
            void addColumn (BaseColumnDesc column){}
            string comment(){string tmp; return tmp;}
    };

    // **************** another piece of bullshit  **********************
    class DataManager{
    };

    // **************** another piece of bullshit  **********************
    class SetupNewTable {
        public:
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
            void bindAll(DataManager){}
            void bindColumn(string,DataManager){}
            void setShapeColumn(string, IPosition){}
    };

    // **************** another piece of bullshit  **********************
    class StManAipsIO: public DataManager{
    };

    // **************** another piece of bullshit  **********************
    class StandardStMan: public DataManager{
        public:
            StandardStMan(int){}
    };

    // **************** another piece of bullshit  **********************
    class IncrementalStMan: public DataManager{
        public:
            IncrementalStMan(int,bool){}
    };
}

#endif
