
#include "casaShore.h"

namespace casacore{

    // *************************************************
    SetupNewTable::SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption, casa::StorageOption const&){}
    SetupNewTable::SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption){}
    SetupNewTable::~SetupNewTable(){}

    // *************************************************
    TableDesc::TableDesc(const String& type, const String& version, TDOption opt){}
    TableDesc::~TableDesc(){}
    void TableDesc::addColumn(BaseColumnDesc column){}

    // *************************************************
    template<class T> ScalarColumnDesc<T>::ScalarColumnDesc(const String& name){}
    template<> ScalarColumnDesc<int>::ScalarColumnDesc(const String& name){}
    template<class T> void ScalarColumnDesc<T>::tableDesc(){}


    // *************************************************
    void BaseColumn::putArrayColumn(void const* data){}
    void BaseColumn::putColumnSlice(casa::Slicer const& slicer, void const* data){}
    void BaseColumn::putArrayColumnCells(casa::RefRows const&, void const*){}
    void BaseColumn::putColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void const*){}
    void BaseColumn::putSlice(unsigned int, casa::Slicer const&, void const*){}
    void BaseColumn::setShape(unsigned int, casa::IPosition const&){}
    void BaseColumn::setShape(unsigned int, casa::IPosition const&, casa::IPosition const&){}
    void BaseColumn::ndimColumn() const{}
    void BaseColumn::shapeColumn() const{}
    void BaseColumn::canAccessSlice(bool&) const{}
    void BaseColumn::canChangeShape() const{}
    void BaseColumn::getArrayColumn(void*) const{}
    void BaseColumn::getColumnSlice(casa::Slicer const&, void*) const{}
    void BaseColumn::getArrayColumnCells(casa::RefRows const&, void*) const{}
    void BaseColumn::getColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void*) const{}
    void BaseColumn::canAccessArrayColumn(bool&) const{}
    void BaseColumn::canAccessColumnSlice(bool&) const{}
    void BaseColumn::canAccessArrayColumnCells(bool&) const{}
    void BaseColumn::ndim(unsigned int) const{}
    void BaseColumn::shape(unsigned int) const{}
    void BaseColumn::getSlice(unsigned int, casa::Slicer const&, void*) const{}
    void BaseColumn::getScalar(unsigned int, int&) const{}

    // *************************************************
    ColumnDesc::ColumnDesc(casa::BaseColumnDesc const&){
        cout << "to this 1" << endl;
        colPtr_p = this;
        cout << colPtr_p << endl;
    }
    ColumnDesc::ColumnDesc(const ColumnDesc& that){
        cout << "to this 2" << endl;
        colPtr_p = this;}
    ColumnDesc::ColumnDesc(){
        cout << "to this 3" << endl;
        colPtr_p = this;}
    ColumnDesc::~ColumnDesc(){}
    void ColumnDesc::name() const{}
    DataType ColumnDesc::dataType() const{
        cout << "return TpInt" << endl;
        return TpInt;}

    // *************************************************

    // *************************************************
    TableError::TableError (Category c){}
    TableError::TableError (const String& str,Category c){}
    TableError::~TableError () throw(){}

    // *************************************************
    TableInvDT::TableInvDT (Category c){}
    TableInvDT::TableInvDT (const String& name,Category c){}
    TableInvDT::~TableInvDT () throw(){}

    // *************************************************
    void TableTrace::trace(int, casa::String const&, char){}
    void TableTrace::trace(int, casa::String const&, char, casa::RefRows const&){}
    void TableTrace::trace(int, casa::String const&, char, long long){}

    // *************************************************
    void DataManager::createScalarColumn(casa::String const&, int, casa::String const&){}

    // *************************************************
    void PlainColumn::keywordSet(){}
    void PlainColumn::columnCache(){}
    void PlainColumn::rwKeywordSet(){}
    void PlainColumn::setShapeColumn(casa::IPosition const&){}
    void PlainColumn::setMaximumCacheSize(unsigned int){}
    void PlainColumn::bind(casa::DataManager*){}
    PlainColumn::PlainColumn(casa::BaseColumnDesc const*, casa::ColumnSet*){}
    PlainColumn::~PlainColumn(){}
    void PlainColumn::isWritable() const{}
    void PlainColumn::nrow() const{}
    void PlainColumn::isBound() const{}
    void PlainColumn::isStored() const{}

    // *************************************************
    TableColumn::TableColumn(casa::Table const&, casa::String const&){}
    TableColumn::TableColumn(casa::TableColumn const&){}
    TableColumn::~TableColumn(){}
    void TableColumn::columnDesc() const{}
    void TableColumn::throwNotWritable() const{}

    // *************************************************
    void ConcatColumn::initialize(unsigned int, unsigned int){}
    void ConcatColumn::keywordSet(){}
    void ConcatColumn::columnCache(){}
    void ConcatColumn::freeIterBuf(void*&, void*&){}
    void ConcatColumn::allocIterBuf(void*&, void*&, casa::CountedPtr<casa::BaseCompare>&){}
    void ConcatColumn::rwKeywordSet(){}
    void ConcatColumn::putArrayColumn(void const*){}
    void ConcatColumn::putColumnSlice(casa::Slicer const&, void const*){}
    void ConcatColumn::putArrayColumnCells(casa::RefRows const&, void const*){}
    void ConcatColumn::putColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void const*){}
    void ConcatColumn::setMaximumCacheSize(unsigned int){}
    void ConcatColumn::put(unsigned int, void const*){}
    void ConcatColumn::putSlice(unsigned int, casa::Slicer const&, void const*){}
    void ConcatColumn::setShape(unsigned int, casa::IPosition const&){}
    void ConcatColumn::setShape(unsigned int, casa::IPosition const&, casa::IPosition const&){}
    void ConcatColumn::ndimColumn() const{}
    void ConcatColumn::shapeColumn() const{}
    void ConcatColumn::canAccessSlice(bool&) const{}
    void ConcatColumn::canChangeShape() const{}
    void ConcatColumn::getArrayColumn(void*) const{}
    void ConcatColumn::getColumnSlice(casa::Slicer const&, void*) const{}
    void ConcatColumn::getArrayColumnCells(casa::RefRows const&, void*) const{}
    void ConcatColumn::getColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void*) const{}
    void ConcatColumn::canAccessArrayColumn(bool&) const{}
    void ConcatColumn::canAccessColumnSlice(bool&) const{}
    void ConcatColumn::canAccessArrayColumnCells(bool&) const{}
    void ConcatColumn::ndim(unsigned int) const{}
    void ConcatColumn::shape(unsigned int) const{}
    void ConcatColumn::getSlice(unsigned int, casa::Slicer const&, void*) const{}
    void ConcatColumn::getScalar(unsigned int, int&) const{}
    ConcatColumn::ConcatColumn(casa::BaseColumnDesc const*, casa::ConcatTable*){}
    ConcatColumn::~ConcatColumn(){}
    void ConcatColumn::isWritable() const{}
    void ConcatColumn::canAccessScalarColumn(bool&) const{}
    void ConcatColumn::canAccessScalarColumnCells(bool&) const{}
    void ConcatColumn::get(unsigned int, void*) const{}
    void ConcatColumn::nrow() const{}
    void ConcatColumn::isStored() const{}
    void ConcatColumn::isDefined(unsigned int) const{}

    // *************************************************
    void ColumnDescSet::addColumn(casa::ColumnDesc const&){}

    // *************************************************
    StorageOption::StorageOption(casa::StorageOption::Option, int){}

    // *************************************************
    void TableLockData::release(bool){}

    // *************************************************
    BaseColumnDesc::BaseColumnDesc(casa::String const&, casa::String const&, casa::String const&, casa::String const&, casa::DataType, casa::String const&, int, unsigned int, casa::IPosition const&, bool, bool, bool){}
    BaseColumnDesc::BaseColumnDesc(casa::BaseColumnDesc const&){}
    BaseColumnDesc::BaseColumnDesc(){}
    BaseColumnDesc::~BaseColumnDesc(){}
    void BaseColumnDesc::handleRemove(casa::ColumnDescSet&){}
    void BaseColumnDesc::handleRename(casa::ColumnDescSet&, casa::String const&){}
    void BaseColumnDesc::renameAction(casa::String const&, casa::String const&){}
    void BaseColumnDesc::handleAdd(casa::ColumnDescSet&){}
    void BaseColumnDesc::checkRename(casa::ColumnDescSet const&, casa::String const&) const{}
    void BaseColumnDesc::checkAdd(casa::ColumnDescSet const&) const{}
    void BaseColumnDesc::tableDesc(){}
    DataType BaseColumnDesc::dataType(){return TpInt;}

    // *************************************************
    TableConformanceError::TableConformanceError(casa::String const&, casa::AipsError::Category){}
    TableConformanceError::~TableConformanceError() throw(){}

    // *************************************************
    TableArrayConformanceError::TableArrayConformanceError(casa::String const&, casa::AipsError::Category){}
    TableArrayConformanceError::~TableArrayConformanceError() throw(){}

    // *************************************************
    Table::Table(SetupNewTable &newtab, uInt nrrows){}
    Table::Table(casa::BaseTable*, bool){}
    Table::Table(casa::SetupNewTable&, unsigned int, bool, casa::Table::EndianFormat, casa::TSMOption const&){}
    Table::~Table(){}

    // *************************************************
    RefRows::RefRows(casa::Vector<unsigned int> const&, bool, bool){}
    RefRows::~RefRows(){}
    void RefRows::convert() const{}
    void RefRows::fillNrows() const{}

    // *************************************************
    TSMOption::TSMOption(casa::TSMOption::Option, int, int){}

    // *************************************************
    void ColumnSet::doLock(casa::FileLocker::LockType, bool){}
    void ColumnSet::getDataManager(unsigned int) const{}

    // *************************************************
    void ConcatRows::findRownr(unsigned int) const{}
}
