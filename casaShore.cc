#include "casaShore.h"

namespace casacore{

    template<> void ScalarColumn<int>::put(uInt rowid, int data){
        cout << "put: rowid=" << rowid << ", data=" << data << endl;
    }

    template<> ScalarColumn<int>::ScalarColumn(casa::Table const&, casa::String const&){

    }

    template<class T> void ScalarColumn<T>::put(uInt rowid, T data){}

}

