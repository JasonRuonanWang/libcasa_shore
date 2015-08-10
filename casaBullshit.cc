#include "casaShore.h"

namespace casacore{


    // *************************************************
    Table::Table(SetupNewTable &newtab, uInt nrrows){}

    // *************************************************
    BaseColumnDesc::BaseColumnDesc(){}

    // *************************************************
    template<> ArrayColumnDesc<bool>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<unsigned char>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<short>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<unsigned short>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<int>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<unsigned int>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<float>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<double>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<Complex>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<DComplex>::ArrayColumnDesc(const String& name){}
    template<> ArrayColumnDesc<String>::ArrayColumnDesc(const String& name){}

    template<> ArrayColumnDesc<bool>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<unsigned char>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<short>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<unsigned short>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<int>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<unsigned int>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<float>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<double>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<Complex>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<DComplex>::ArrayColumnDesc(const String& name, int ndim){}
    template<> ArrayColumnDesc<String>::ArrayColumnDesc(const String& name, int ndim){}

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
    template<> ScalarColumnDesc<String>::ScalarColumnDesc(const String& name){}

    template<> ScalarColumnDesc<bool>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<unsigned char>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<short>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<unsigned short>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<int>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<unsigned int>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<float>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<double>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<Complex>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<DComplex>::ScalarColumnDesc(const String& name, string comment){}
    template<> ScalarColumnDesc<String>::ScalarColumnDesc(const String& name, string comment){}
    // *************************************************


    TableDesc::TableDesc(const String& type, const String& version, TDOption opt){}
    void TableDesc::addColumn(BaseColumnDesc column){}
    string TableDesc::comment(){string tmp; return tmp;}

    // *************************************************
    SetupNewTable::SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
    void SetupNewTable::bindAll(DataManager){}
    void SetupNewTable::bindColumn(string,DataManager){}


}
