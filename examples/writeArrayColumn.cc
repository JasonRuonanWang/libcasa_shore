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
#include <casacore/tables/Tables/ArrColDesc.h>
#include <casacore/tables/Tables/ArrayColumn.h>
#include <casacore/tables/DataMan/TiledShapeStMan.h>
#include <casacore/casa/namespace.h>

int main(int argc, char **argv){

    if (argc < 2){
        cout << "./wAdiosStMan /path/to/file" << endl;
        return -1;
    }
    string filename = argv[1];

    int NrRows = 4;

    IPosition data_pos = IPosition(3,NrRows,6,5);

    Array<Bool> arr_Bool(data_pos);
    Array<Char> arr_Char(data_pos);
    Array<uChar> arr_uChar(data_pos);
    Array<Short> arr_Short(data_pos);
    Array<uShort> arr_uShort(data_pos);
    Array<Int> arr_Int(data_pos);
    Array<uInt> arr_uInt(data_pos);
    Array<Float> arr_Float(data_pos);
    Array<Double> arr_Double(data_pos);
    Array<Complex> arr_Complex(data_pos);
    Array<DComplex> arr_DComplex(data_pos);


    // define a table description & add a scalar column and an array column
    TableDesc td("", "1", TableDesc::Scratch);
    td.addColumn (ArrayColumnDesc<Bool>("data_Bool", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Char>("data_Char", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<uChar>("data_uChar", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Short>("data_Short", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<uShort>("data_uShort", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Int>("data_Int", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<uInt>("data_uInt", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Float>("data_Float", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Double>("data_Double", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<Complex>("data_Complex", -1, ColumnDesc::FixedShape));
    td.addColumn (ArrayColumnDesc<DComplex>("data_DComplex", -1, ColumnDesc::FixedShape));

    // create a table instance, bind it to the storage manager & allocate rows
    SetupNewTable newtab(filename, td, Table::New);
    newtab.setShapeColumn("data_Bool", data_pos);
    newtab.setShapeColumn("data_Char", data_pos);
    newtab.setShapeColumn("data_uChar", data_pos);
    newtab.setShapeColumn("data_Short", data_pos);
    newtab.setShapeColumn("data_uShort", data_pos);
    newtab.setShapeColumn("data_Int", data_pos);
    newtab.setShapeColumn("data_uInt", data_pos);
    newtab.setShapeColumn("data_Float", data_pos);
    newtab.setShapeColumn("data_Double", data_pos);
    newtab.setShapeColumn("data_Complex", data_pos);
    newtab.setShapeColumn("data_DComplex", data_pos);
    Table tab(newtab,  NrRows);

    // define column objects and link them to the table
    ArrayColumn<Bool> col_Bool (tab, "data_Bool");
    ArrayColumn<Char> col_Char (tab, "data_Char");
    ArrayColumn<uChar> col_uChar (tab, "data_uChar");
    ArrayColumn<Short> col_Short (tab, "data_Short");
    ArrayColumn<uShort> col_uShort (tab, "data_uShort");
    ArrayColumn<Int> col_Int (tab, "data_Int");
    ArrayColumn<uInt> col_uInt (tab, "data_uInt");
    ArrayColumn<Float> col_Float (tab, "data_Float");
    ArrayColumn<Double> col_Double (tab, "data_Double");
    ArrayColumn<Complex> col_Complex (tab, "data_Complex");
    ArrayColumn<DComplex> col_DComplex (tab, "data_DComplex");

    // write data into the column objects
    arr_Bool = 1; col_Bool.putColumn(arr_Bool);
    arr_Char = 1; col_Char.putColumn(arr_Char);
    arr_uChar = 2; col_uChar.putColumn(arr_uChar);
    arr_Short = -3; col_Short.putColumn(arr_Short);
    arr_uShort = 4; col_uShort.putColumn(arr_uShort);
    indgen(arr_Int, 100); col_Int.putColumn(arr_Int);
    indgen(arr_uInt, (uInt)200); col_uInt.putColumn(arr_uInt);
    indgen(arr_Float, (Float)300, (Float)0.1); col_Float.putColumn(arr_Float);
    indgen(arr_Double, (Double)400, (Double)0.01); col_Double.putColumn(arr_Double);
    indgen(arr_Complex, (Complex)500, (Complex)0.001); col_Complex.putColumn(arr_Complex);
    arr_DComplex = 5; col_DComplex.putColumn(arr_DComplex);

    Vector<Bool> vec_Bool = arr_Bool.reform(IPosition(1,arr_Bool.nelements()));
    cout << endl << "Column: data_Bool, Shape: " << arr_Bool.shape() << endl;
    for (int i=0; i<arr_Bool.nelements(); i++){
        cout << vec_Bool[i] << "  ";
        if ((i+1) % (arr_Bool.shape())(0) == 0)
            cout << endl;
    }

    Vector<Char> vec_Char = arr_Char.reform(IPosition(1,arr_Char.nelements()));
    cout << endl << "Column: data_Char, Shape: " << arr_Char.shape() << endl;
    for (int i=0; i<arr_Char.nelements(); i++){
        cout << (uInt)vec_Char[i] << "  ";
        if ((i+1) % (arr_Char.shape())(0) == 0)
            cout << endl;
    }

    Vector<uChar> vec_uChar = arr_uChar.reform(IPosition(1,arr_uChar.nelements()));
    cout << endl << "Column: data_uChar, Shape: " << arr_uChar.shape() << endl;
    for (int i=0; i<arr_uChar.nelements(); i++){
        cout << (uInt)vec_uChar[i] << "  ";
        if ((i+1) % (arr_uChar.shape())(0) == 0)
            cout << endl;
    }

    Vector<Short> vec_Short = arr_Short.reform(IPosition(1,arr_Short.nelements()));
    cout << endl << "Column: data_Short, Shape: " << arr_Short.shape() << endl;
    for (int i=0; i<arr_Short.nelements(); i++){
        cout << vec_Short[i] << "  ";
        if ((i+1) % (arr_Short.shape())(0) == 0)
            cout << endl;
    }

    Vector<uShort> vec_uShort = arr_uShort.reform(IPosition(1,arr_uShort.nelements()));
    cout << endl << "Column: data_uShort, Shape: " << arr_uShort.shape() << endl;
    for (int i=0; i<arr_uShort.nelements(); i++){
        cout << vec_uShort[i] << "  ";
        if ((i+1) % (arr_uShort.shape())(0) == 0)
            cout << endl;
    }

    Vector<Int> vec_Int = arr_Int.reform(IPosition(1,arr_Int.nelements()));
    cout << endl << "Column: data_Int, Shape: " << arr_Int.shape() << endl;
    for (int i=0; i<arr_Int.nelements(); i++){
        cout << vec_Int[i] << "  ";
        if ((i+1) % (arr_Int.shape())(0) == 0)
            cout << endl;
    }

    Vector<uInt> vec_uInt = arr_uInt.reform(IPosition(1,arr_uInt.nelements()));
    cout << endl << "Column: data_uInt, Shape: " << arr_uInt.shape() << endl;
    for (int i=0; i<arr_uInt.nelements(); i++){
        cout << vec_uInt[i] << "  ";
        if ((i+1) % (arr_uInt.shape())(0) == 0)
            cout << endl;
    }

    Vector<Float> vec_Float = arr_Float.reform(IPosition(1,arr_Float.nelements()));
    cout << endl << "Column: data_Float, Shape: " << arr_Float.shape() << endl;
    for (int i=0; i<arr_Float.nelements(); i++){
        cout << vec_Float[i] << "  ";
        if ((i+1) % (arr_Float.shape())(0) == 0)
            cout << endl;
    }

    Vector<Double> vec_Double = arr_Double.reform(IPosition(1,arr_Double.nelements()));
    cout << endl << "Column: data_Double, Shape: " << arr_Double.shape() << endl;
    for (int i=0; i<arr_Double.nelements(); i++){
        cout << vec_Double[i] << "  ";
        if ((i+1) % (arr_Double.shape())(0) == 0)
            cout << endl;
    }

    Vector<Complex> vec_Complex = arr_Complex.reform(IPosition(1,arr_Complex.nelements()));
    cout << endl << "Column: data_Complex, Shape: " << arr_Complex.shape() << endl;
    for (int i=0; i<arr_Complex.nelements(); i++){
        cout << vec_Complex[i] << "  ";
        if ((i+1) % (arr_Complex.shape())(0) == 0)
            cout << endl;
    }

    Vector<DComplex> vec_DComplex = arr_DComplex.reform(IPosition(1,arr_DComplex.nelements()));
    cout << endl << "Column: data_DComplex, Shape: " << arr_DComplex.shape() << endl;
    for (int i=0; i<arr_DComplex.nelements(); i++){
        cout << vec_DComplex[i] << "  ";
        if ((i+1) % (arr_DComplex.shape())(0) == 0)
            cout << endl;
    }


    return 0;
}


