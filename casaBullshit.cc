#include "casaShore.h"

namespace casacore{


    // *************************************************
    Table::Table(SetupNewTable &newtab, uInt nrrows){}

    // *************************************************
    BaseColumnDesc::BaseColumnDesc(){}

    TableDesc::TableDesc(const String& type, const String& version, TDOption opt){}
    void TableDesc::addColumn(BaseColumnDesc column){}
    string TableDesc::comment(){string tmp; return tmp;}

    // *************************************************
    SetupNewTable::SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
    void SetupNewTable::bindAll(DataManager){}
    void SetupNewTable::bindColumn(string,DataManager){}


}
