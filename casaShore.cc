#include "casaShore.h"

namespace casacore{

    template<> void ScalarColumn<bool>::put(uInt rowid, bool data){
    }
    template<> void ScalarColumn<unsigned char>::put(uInt rowid, unsigned char data){
    }
    template<> void ScalarColumn<short>::put(uInt rowid, short data){
    }
    template<> void ScalarColumn<unsigned short>::put(uInt rowid, unsigned short data){
    }
    template<> void ScalarColumn<int>::put(uInt rowid, int data){
        cout << "put: rowid=" << rowid << ", data=" << data << endl;
    }
    template<> void ScalarColumn<unsigned int>::put(uInt rowid, uInt data){
    }
    template<> void ScalarColumn<float>::put(uInt rowid, float data){
    }
    template<> void ScalarColumn<double>::put(uInt rowid, double data){
    }
    template<> void ScalarColumn<Complex>::put(uInt rowid, Complex data){
    }
    template<> void ScalarColumn<DComplex>::put(uInt rowid, DComplex data){
    }

    template<> ScalarColumn<bool>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<unsigned char>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<short>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<unsigned short>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<int>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<unsigned int>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<float>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<double>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<Complex>::ScalarColumn(casa::Table const&, casa::String const&){
    }

    template<> ScalarColumn<DComplex>::ScalarColumn(casa::Table const&, casa::String const&){
    }
}

