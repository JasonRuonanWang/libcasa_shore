//    (c) University of Western Australia
//    International Centre of Radio Astronomy Research
//    M468, 35 Stirling Hwy
//    Crawley, Perth WA 6009
//    Australia
//
//    This library is free software: you can redistribute it and/or
//    modify it under the terms of the GNU General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this library. If not, see <http://www.gnu.org/licenses/>.
//
//    Any bugs, questions, concerns and/or suggestions please email to
//    jason.wang@icrar.org


#include <casacore/tables/Tables/SetupNewTab.h>
#include <casacore/tables/Tables/ScaColDesc.h>
#include <casacore/casa/namespace.h>

int main(int argc, char **argv){

    if (argc < 2){
        cout << "missing data object id" << endl;
        return -1;
    }

    int NrRows = 4;

    string filename = argv[1];
    if (argc ==3){
        NrRows = atoi(argv[2]);
    }

    // define a table description and add a scalar column
    TableDesc td("", "1", TableDesc::Scratch);
    td.addColumn (ScalarColumnDesc<Bool>("index_Bool"));
    td.addColumn (ScalarColumnDesc<Char>("index_Char"));
    td.addColumn (ScalarColumnDesc<uChar>("index_uChar"));
    td.addColumn (ScalarColumnDesc<Short>("index_Short"));
    td.addColumn (ScalarColumnDesc<uShort>("index_uShort"));
    td.addColumn (ScalarColumnDesc<Int>("index_Int"));
    td.addColumn (ScalarColumnDesc<uInt>("index_uInt"));
    td.addColumn (ScalarColumnDesc<Float>("index_Float"));
    td.addColumn (ScalarColumnDesc<Double>("index_Double"));
    td.addColumn (ScalarColumnDesc<Complex>("index_Complex"));
    td.addColumn (ScalarColumnDesc<DComplex>("index_DComplex"));

    // create a table instance, bind it to the storage manager
    SetupNewTable newtab(filename, td, Table::New);
    Table tab(newtab, NrRows);

    // define column objects and link them to the table
    ScalarColumn<Bool> col_Bool (tab, "index_Bool");
    ScalarColumn<Char> col_Char (tab, "index_Char");
    ScalarColumn<uChar> col_uChar (tab, "index_uChar");
    ScalarColumn<Short> col_Short (tab, "index_Short");
    ScalarColumn<uShort> col_uShort (tab, "index_uShort");
    ScalarColumn<Int> col_Int (tab, "index_Int");
    ScalarColumn<uInt> col_uInt (tab, "index_uInt");
    ScalarColumn<Float> col_Float (tab, "index_Float");
    ScalarColumn<Double> col_Double (tab, "index_Double");
    ScalarColumn<Complex> col_Complex (tab, "index_Complex");
    ScalarColumn<DComplex> col_DComplex (tab, "index_DComplex");

    Vector<Bool> vec_Bool(NrRows);               indgen(vec_Bool);
    Vector<Char> vec_Char(NrRows);               indgen(vec_Char);
    Vector<uChar> vec_uChar(NrRows);             indgen(vec_uChar);
    Vector<Short> vec_Short(NrRows);             indgen(vec_Short);
    Vector<uShort> vec_uShort(NrRows);           indgen(vec_uShort);
    Vector<Int> vec_Int(NrRows);                 indgen(vec_Int);
    Vector<uInt> vec_uInt(NrRows);               indgen(vec_uInt);
    Vector<Float> vec_Float(NrRows);             indgen(vec_Float);
    Vector<Double> vec_Double(NrRows);           indgen(vec_Double);
    Vector<Complex> vec_Complex(NrRows);         indgen(vec_Complex);
    Vector<DComplex> vec_DComplex(NrRows);       indgen(vec_DComplex);

    // write data into the column objects
    col_Bool.putColumn (vec_Bool);
    col_Char.putColumn (vec_Char);
    col_uChar.putColumn (vec_uChar);
    col_Short.putColumn (vec_Short);
    col_uShort.putColumn (vec_uShort);
    col_Int.putColumn (vec_Int);
    col_uInt.putColumn (vec_uInt);
    col_Float.putColumn (vec_Float);
    col_Double.putColumn (vec_Double);
    col_Complex.putColumn (vec_Complex);
    col_DComplex.putColumn (vec_DComplex);

    return 0;
}


