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

#include <casacore/tables/Tables/ScalarColumn.h>
#include <casacore/casa/namespace.h>

int main(int argc, char **argv){
    if (argc < 2){
        cout << "./rAdiosStMan /path/to/file" << endl;
        return -1;
    }
    string filename = argv[1];
    Table casa_table(filename);
    uInt gettingRow = 1;
    if (argc == 3){
        gettingRow = atoi(argv[2]);
    }

    ROScalarColumn<Bool> col_Bool(casa_table, "index_Bool");
    Bool vec_Bool = col_Bool.get(gettingRow);
    cout << "index_Bool column: " << vec_Bool << endl;

    ROScalarColumn<Char> col_Char(casa_table, "index_Char");
    Char vec_Char = col_Char.get(gettingRow);
    cout << "index_Char column: " << +vec_Char << endl;

    ROScalarColumn<uChar> col_uChar(casa_table, "index_uChar");
    uChar vec_uChar = col_uChar.get(gettingRow);
    cout << "index_uChar column: " << +vec_uChar << endl;

    ROScalarColumn<Short> col_Short(casa_table, "index_Short");
    Short vec_Short = col_Short.get(gettingRow);
    cout << "index_Short column: " << vec_Short << endl;

    ROScalarColumn<uShort> col_uShort(casa_table, "index_uShort");
    uShort vec_uShort = col_uShort.get(gettingRow);
    cout << "index_uShort column: " << vec_uShort << endl;

    ROScalarColumn<Int> col_Int(casa_table, "index_Int");
    Int vec_Int = col_Int.get(gettingRow);
    cout << "index_Int column: " << vec_Int << endl;

    ROScalarColumn<uInt> col_uInt(casa_table, "index_uInt");
    uInt vec_uInt = col_uInt.get(gettingRow);
    cout << "index_uInt column: " << vec_uInt << endl;

    ROScalarColumn<Float> col_Float(casa_table, "index_Float");
    Float vec_Float = col_Float.get(gettingRow);
    cout << "index_Float column: " << vec_Float << endl;

    ROScalarColumn<Double> col_Double(casa_table, "index_Double");
    Double vec_Double = col_Double.get(gettingRow);
    cout << "index_Double column: " << vec_Double << endl;

    ROScalarColumn<Complex> col_Complex(casa_table, "index_Complex");
    Complex vec_Complex = col_Complex.get(gettingRow);
    cout << "index_Complex column: " << vec_Complex << endl;

    ROScalarColumn<DComplex> col_DComplex(casa_table, "index_DComplex");
    DComplex vec_DComplex = col_DComplex.get(gettingRow);
    cout << "index_DComplex column: " << vec_DComplex << endl;

    return 0;
}


