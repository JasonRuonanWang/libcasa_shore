#include <casacore/tables/Tables/SetupNewTab.h>
#include <casacore/tables/Tables/ScaColDesc.h>
#include <casacore/casa/namespace.h>

using namespace std;
using namespace casacore;

int main(int argc, char **argv){

    string filename = "aaa.ms";

    int NrRows = 4;

    // define a table description and add a scalar column
    TableDesc td("", "1", TableDesc::Scratch);
    td.addColumn (ScalarColumnDesc<Int>("index_Int"));

    // create a table instance, bind it to the storage manager
    SetupNewTable newtab(filename, td, Table::New);
    Table tab(newtab, NrRows);

    // define column objects and link them to the table
    ScalarColumn<Int> col_Int (tab, "index_Int");

    // write data into the column objects
    for (uInt i=0; i<NrRows; i++) {
        col_Int.put (i, i);
    }

    return 0;
}


