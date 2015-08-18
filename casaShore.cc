#include "casaShore.h"

namespace casacore{

    SetupNewTable::SetupNewTable(casa::String const& id, casa::TableDesc const&, casa::Table::TableOption){
        doid = id;
        cout << "id=" << id << endl;
    }

    Table::Table(SetupNewTable &newtab, uInt nrrows, bool a, EndianFormat b){
        doid = newtab.doid;
        cout << "doid=" << doid << endl;
    }


}

