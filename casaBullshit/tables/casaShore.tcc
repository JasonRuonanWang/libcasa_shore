namespace casacore{

    template<class T> ScalarColumn<T>::ScalarColumn(Table const& tab, String const& name){
        doid = tab.doid;
        columnName = name;
    }

    template<class T> void ScalarColumn<T>::put(uInt rowid, T data){
        cout << "Table Data Object ID: " << doid << ", Column: " << columnName << ", put Row " << rowid << ", Data " <<  data << endl;
    }

}
