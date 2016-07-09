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
/*
    template<> void ScalarColumn<bool>::put(uInt rowid, bool data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<char>::put(uInt rowid, char data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<unsigned char>::put(uInt rowid, unsigned char data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<short>::put(uInt rowid, short data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<unsigned short>::put(uInt rowid, unsigned short data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<int>::put(uInt rowid, int data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<unsigned int>::put(uInt rowid, unsigned int data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<float>::put(uInt rowid, float data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<double>::put(uInt rowid, double data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<Complex>::put(uInt rowid, Complex data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
    template<> void ScalarColumn<DComplex>::put(uInt rowid, DComplex data){
        shapePtr[0]=1; shapePtr[1]=1;
        shorePut(TableColumn::doid.c_str(), TableColumn::columnName.c_str(), rowid, 1, shapePtr, TableColumn::dtype, &data);
    }
*/

    template<> ScalarColumn<bool>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeBool; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<char>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeChar; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned char>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUChar; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<short>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeShort; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned short>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUShort; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<int>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeInt; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned int>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUInt; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<float>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeFloat; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<double>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeDouble; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<Complex>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeComplex; doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<DComplex>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeDComplex; doid = tab.doid; columnName = name;
    }

    template<> ArrayColumn<bool>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeBool; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<char>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeChar; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned char>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUChar; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<short>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeShort; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned short>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUShort; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<int>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeInt; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned int>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUInt; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<float>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeFloat; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<double>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeDouble; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<Complex>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeComplex; doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<DComplex>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeDComplex; doid = tab.doid; columnName = name;
    }


}


