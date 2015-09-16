#include "casaShore.h"

namespace casacore{

    SetupNewTable::SetupNewTable(casa::String const& id, casa::TableDesc const&, casa::Table::TableOption){
        doid = id;
    }

    Table::Table(SetupNewTable &newtab, uInt nrrows, bool a, EndianFormat b){
        doid = newtab.doid;
    }

    // *********************************************************************
    // for non-removal version
    PlainColumn::PlainColumn (const BaseColumnDesc* cdp, ColumnSet* csp){}
    PlainColumn::~PlainColumn(){}
    void PlainColumn::keywordSet (){}
    void PlainColumn::rwKeywordSet (){}
    void PlainColumn::columnCache (){}
    void PlainColumn::setShapeColumn (const IPosition &){}
    void PlainColumn::setMaximumCacheSize (uInt){}
    void PlainColumn::bind (DataManager *){}
    Bool PlainColumn::isWritable () const{return 0;}
    uInt PlainColumn::nrow () const{return 0;}
    Bool PlainColumn::isBound () const{return 0;}
    Bool PlainColumn::isStored () const{return 0;}
    BaseColumn::BaseColumn(){}
    BaseColumn::BaseColumn(const BaseColumnDesc *){}
    void BaseColumn::putArrayColumn(const void*){}
    void BaseColumn::putColumnSlice(const Slicer &, const void *){}
    void BaseColumn::putArrayColumnCells (const RefRows &, const void *){}
    void BaseColumn::putColumnSliceCells (const RefRows &, const Slicer &, const void *){}
    void BaseColumn::putSlice (uInt, const Slicer &, const void *){}
    void BaseColumn::setShape (uInt, const IPosition &){}
    void BaseColumn::setShape (uInt, const IPosition &, const IPosition &){}
    uInt BaseColumn::ndimColumn () const{return 0;}
    IPosition BaseColumn::shapeColumn () const{IPosition p; return p;}
    Bool BaseColumn::canAccessSlice (Bool &reask) const{return 0;}
    Bool BaseColumn::canChangeShape () const{return 0;}
    void BaseColumn::getArrayColumn (void *dataPtr) const{}
    void BaseColumn::getColumnSlice (const Slicer &, void *dataPtr) const{}
    void BaseColumn::getArrayColumnCells (const RefRows &rownrs, void *dataPtr) const{}
    void BaseColumn::getColumnSliceCells (const RefRows &rownrs, const Slicer &, void *dataPtr) const{}
    Bool BaseColumn::canAccessArrayColumn (Bool &reask) const{return 0;}
    Bool BaseColumn::canAccessColumnSlice (Bool &reask) const{return 0;}
    Bool BaseColumn::canAccessArrayColumnCells (Bool &reask) const{return 0;}
    uInt BaseColumn::ndim (uInt rownr) const{return 0;}
    IPosition BaseColumn::shape (uInt rownr) const{IPosition p; return p;}
    void BaseColumn::getSlice (uInt rownr, const Slicer &, void *dataPtr) const{}
    TableInvDT::TableInvDT (Category){}
    TableInvDT::~TableInvDT () throw (){}
    void ConcatColumn::initialize (uInt, uInt){}
    void ConcatColumn::keywordSet (){}
    void ConcatColumn::rwKeywordSet (){}
    void ConcatColumn::columnCache (){}
    void ConcatColumn::freeIterBuf (void *&, void *&){}
    void ConcatColumn::allocIterBuf (void *&, void *&, CountedPtr<BaseCompare> &){}
    void ConcatColumn::putArrayColumn(const void*){}
    void ConcatColumn::putColumnSlice(const Slicer &, const void *){}
    void ConcatColumn::putArrayColumnCells (const RefRows &, const void *){}
    void ConcatColumn::putColumnSliceCells (const RefRows &, const Slicer &, const void *){}
    void ConcatColumn::putSlice (uInt, const Slicer &, const void *){}
    void ConcatColumn::put (uInt, const void *){}
    void ConcatColumn::setMaximumCacheSize (uInt){}
    void ConcatColumn::setShape (uInt, const IPosition &){}
    void ConcatColumn::setShape (uInt, const IPosition &, const IPosition &){}
    Bool ConcatColumn::isWritable () const{return 0;}
    uInt ConcatColumn::ndimColumn () const{return 0;}
    IPosition ConcatColumn::shapeColumn () const{IPosition p; return p;}
    Bool ConcatColumn::canAccessSlice (Bool &reask) const{return 0;}
    Bool ConcatColumn::canChangeShape () const{return 0;}
    void ConcatColumn::getArrayColumnCells (const RefRows &rownrs, void *dataPtr) const{}
    void ConcatColumn::getArrayColumn (void *dataPtr) const{}
    void ConcatColumn::getColumnSlice (const Slicer &, void *dataPtr) const{}
    void ConcatColumn::getColumnSliceCells (const RefRows &rownrs, const Slicer &, void *dataPtr) const{}
    Bool ConcatColumn::canAccessArrayColumn (Bool &reask) const{return 0;}
    Bool ConcatColumn::canAccessColumnSlice (Bool &reask) const{return 0;}
    Bool ConcatColumn::canAccessArrayColumnCells (Bool &reask) const{return 0;}
    Bool ConcatColumn::canAccessScalarColumn (Bool &reask) const{return 0;}
    Bool ConcatColumn::canAccessScalarColumnCells (Bool &reask) const{return 0;}
    void ConcatColumn::get (uInt rownr, void *dataPtr) const{}
    uInt ConcatColumn::ndim (uInt rownr) const{return 0;}
    uInt ConcatColumn::nrow () const{return 0;}
    IPosition ConcatColumn::shape (uInt rownr) const{IPosition p; return p;}
    void ConcatColumn::getSlice (uInt rownr, const Slicer &, void *dataPtr) const{}
    Bool ConcatColumn::isStored () const{return 0;}
    Bool ConcatColumn::isDefined (uInt rownr) const{return 0;}
    void BaseColumnDesc::handleRemove (ColumnDescSet &){}
    void BaseColumnDesc::handleRename (ColumnDescSet &, const String&){}
    void BaseColumnDesc::renameAction (const String &newName, const String &oldName){}
    void BaseColumnDesc::handleAdd (ColumnDescSet &cds){}
    void BaseColumnDesc::checkRename (const ColumnDescSet &cds, const String &newName) const{}
    void BaseColumnDesc::checkAdd (const ColumnDescSet &cds) const{}
    const TableDesc* BaseColumnDesc::tableDesc () const{return 0;}
    TableDesc* BaseColumnDesc::tableDesc () {return 0;}
    TableConformanceError::~TableConformanceError () throw (){}
    TableArrayConformanceError::~TableArrayConformanceError () throw (){}
    // *********************************************************************
}

