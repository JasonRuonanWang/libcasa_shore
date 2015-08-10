#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/IPosition.h>

namespace casacore{

    class SetupNewTable;

    template<class T> class ScalarColumn{
        public:
            ScalarColumn(casa::Table const&, casa::String const&);
            void put(uInt rowid, T data);
    };



    // **************** below this line is bullshit *****************

    class Table {
        public:
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            Table(SetupNewTable &newtab, uInt nrrows);
    };

    class BaseColumnDesc{
        public:
            BaseColumnDesc ();
    };

    template<class T> class ScalarColumnDesc : public BaseColumnDesc {
        public:
            ScalarColumnDesc(const String& name);
    };

    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(const String& type, const String& version, TDOption = Old);
            void addColumn (BaseColumnDesc column);
    };

    class DataManager{
    };

    class SetupNewTable {
        public:
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption);
            void bindAll(DataManager);
    };

}

#endif
