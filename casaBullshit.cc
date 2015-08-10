#include "casaShore.h"

namespace casacore{


    // *************************************************
    Table::Table(SetupNewTable &newtab, uInt nrrows){}

    // *************************************************
    BaseColumnDesc::BaseColumnDesc(){}

    // *************************************************
    template<> ScalarColumnDesc<bool>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<unsigned char>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<short>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<unsigned short>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<int>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<unsigned int>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<float>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<double>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<Complex>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<DComplex>::ScalarColumnDesc(const String& name){}

    // *************************************************
    TableDesc::TableDesc(const String& type, const String& version, TDOption opt){}
    void TableDesc::addColumn(BaseColumnDesc column){}

    // *************************************************
    SetupNewTable::SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
    void SetupNewTable::bindAll(DataManager){}


}
