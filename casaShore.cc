#include "casaShore.h"

namespace casacore{

    SetupNewTable::SetupNewTable(casa::String const& id, casa::TableDesc const&, casa::Table::TableOption){
        doid = id;
    }

    Table::Table(SetupNewTable &newtab, uInt nrrows, bool a, EndianFormat b){
        doid = newtab.doid;
    }

    Table::Table(string filename){
        doid = filename;
    }

    template<> TableColumn<bool>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeBool; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<char>::TableColumn(Table const& tab, String const& name){
        cout << "shoreTypeChar, " <<shoreTypeChar << endl;
        dtype = shoreTypeChar; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<unsigned char>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeUChar; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<short>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeShort; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<unsigned short>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeUShort; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<int>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeInt; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<unsigned int>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeUInt; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<float>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeFloat; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<double>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeDouble; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<Complex>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeComplex; doid = tab.doid; columnName = name;
    }
    template<> TableColumn<DComplex>::TableColumn(Table const& tab, String const& name){
        dtype = shoreTypeDComplex; doid = tab.doid; columnName = name;
    }


}


