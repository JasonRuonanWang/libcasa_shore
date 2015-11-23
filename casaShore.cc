#include "casaShore.h"
extern "C"{
#include <shoreClient.h>
}

namespace casacore{

    SetupNewTable::SetupNewTable(casa::String const& id, casa::TableDesc const&, casa::Table::TableOption){
        doid = id;
    }

    Table::Table(SetupNewTable &newtab, uInt nrrows, bool a, EndianFormat b){
        doid = newtab.doid;
    }

    template<> ScalarColumn<bool>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeBool;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<char>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeChar;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned char>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUChar;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<short>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeShort;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned short>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUShort;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<int>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeInt;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<unsigned int>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeUInt;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<float>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeFloat;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<double>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeDouble;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<Complex>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeComplex;
        doid = tab.doid; columnName = name;
    }
    template<> ScalarColumn<DComplex>::ScalarColumn(Table const& tab, String const& name){
        dtype = shoreTypeDComplex;
        doid = tab.doid; columnName = name;
    }

    template<> void ScalarColumn<bool>::put(uInt rowid, bool data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<char>::put(uInt rowid, char data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<unsigned char>::put(uInt rowid, unsigned char data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<short>::put(uInt rowid, short data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<unsigned short>::put(uInt rowid, unsigned short data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<int>::put(uInt rowid, int data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<unsigned int>::put(uInt rowid, unsigned int data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<float>::put(uInt rowid, float data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<double>::put(uInt rowid, double data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<Complex>::put(uInt rowid, Complex data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ScalarColumn<DComplex>::put(uInt rowid, DComplex data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }


    template<> ArrayColumn<bool>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeBool;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<char>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeChar;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned char>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUChar;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<short>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeShort;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned short>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUShort;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<int>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeInt;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<unsigned int>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeUInt;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<float>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeFloat;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<double>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeDouble;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<Complex>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeComplex;
        doid = tab.doid; columnName = name;
    }
    template<> ArrayColumn<DComplex>::ArrayColumn(Table const& tab, String const& name){
        dtype = shoreTypeDComplex;
        doid = tab.doid; columnName = name;
    }

    template<> void ArrayColumn<bool>::put(uInt rowid, Array<bool> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<char>::put(uInt rowid, Array<char> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<unsigned char>::put(uInt rowid, Array<unsigned char> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<short>::put(uInt rowid, Array<short> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<unsigned short>::put(uInt rowid, Array<unsigned short> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<int>::put(uInt rowid, Array<int> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<unsigned int>::put(uInt rowid, Array<unsigned int> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<float>::put(uInt rowid, Array<float> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<double>::put(uInt rowid, Array<double> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<Complex>::put(uInt rowid, Array<Complex> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }
    template<> void ArrayColumn<DComplex>::put(uInt rowid, Array<DComplex> data){
        shorePut(doid.c_str(), columnName.c_str(), rowid, 0, dtype, &data);
    }

}

