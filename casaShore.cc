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


