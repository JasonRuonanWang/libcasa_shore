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

    template<> void ArrayColumn<bool>::put(uInt rowid, const Array<bool> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const bool *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<char>::put(uInt rowid, const Array<char> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const char *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<unsigned char>::put(uInt rowid, const Array<unsigned char> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const unsigned char *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<short>::put(uInt rowid, const Array<short> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const short *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<unsigned short>::put(uInt rowid, const Array<unsigned short> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const unsigned short *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<int>::put(uInt rowid, const Array<int> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const int *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<unsigned int>::put(uInt rowid, const Array<unsigned int> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const unsigned int *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<float>::put(uInt rowid, const Array<float> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const float *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<double>::put(uInt rowid, const Array<double> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const double *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<Complex>::put(uInt rowid, const Array<Complex> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const Complex *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }
    template<> void ArrayColumn<DComplex>::put(uInt rowid, const Array<DComplex> data){
        shapePtr[0] = data.ndim();
        shape = data.shape();
        for (unsigned int i=0; i<shapePtr[0]; i++){
            shapePtr[i+1] = shape[i];
        }
        bool deleteIt;
        const DComplex *dataPtr = data.getStorage (deleteIt);
        shorePut(doid.c_str(), columnName.c_str(), rowid, 1, shapePtr, dtype, dataPtr);
        data.freeStorage(dataPtr, deleteIt);
    }



}


