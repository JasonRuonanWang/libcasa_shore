#ifndef CASA_SHORE_H
#define CASA_SHORE_H

#include <casacore/casa/Utilities/DataType.h>
#include <casacore/casa/Arrays/Slicer.h>
#include <casacore/casa/Arrays/IPosition.h>

namespace casacore{

    class SetupNewTable;
    class BaseColumnDesc;
    class BaseTable;
    class DataManager;
    class ColumnDesc;
    class ColumnSet;

    class TSMOption{
        enum Option {Old=1, New, NewNoReplace, Scratch, Update, Delete};
        TSMOption(casa::TSMOption::Option, int, int);
    };

    class Table {
        public:
            enum EndianFormat {BigEndian, LittleEndian, LocalEndian, AipsrcEndian};
            enum TableOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            Table(SetupNewTable &newtab, uInt nrrows);
            Table(casa::BaseTable*, bool);
            Table(casa::SetupNewTable&, unsigned int, bool, casa::Table::EndianFormat, casa::TSMOption const&);
            ~Table();
    };


    class ColumnDesc{
        public:
            ColumnDesc(const BaseColumnDesc&);
            ColumnDesc(const ColumnDesc& that);
            ColumnDesc();
            ~ColumnDesc();
            void name() const;
            DataType dataType() const;
            ColumnDesc* colPtr_p;
    };

    class ColumnDescSet{
        public:
            void addColumn(casa::ColumnDesc const&);
    };

    class BaseColumnDesc{
        public:
            BaseColumnDesc (const String& name, const String& comment,
                    const String& dataManagerType,
                    const String& dataManagerGroup,
                    DataType, const String& dataTypeId,
                    Int options, uInt ndim, const IPosition& shape,
                    Bool isScalar, Bool isArray, Bool isTable);
            BaseColumnDesc (const BaseColumnDesc&);
            BaseColumnDesc ();
            ~BaseColumnDesc ();
            void handleRemove (ColumnDescSet& cds);
            void handleRename (ColumnDescSet& cds, const String& oldName);
            void renameAction (const String& newName, const String& oldName);
            void handleAdd (ColumnDescSet& cds);
            virtual void checkRename (const ColumnDescSet& cds, const String& newName) const;
            void checkAdd (const ColumnDescSet& cds) const;
            void tableDesc();
            DataType dataType();
    };

    class TableDesc {
        public:
            enum TDOption {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            TableDesc(const String& type, const String& version, TDOption = Old);
            ~TableDesc();
            void addColumn (BaseColumnDesc column);
    };

    class StorageOption{
        public:
            enum Option {Old=1, New, NewNoReplace, Scratch, Update, Delete};
            StorageOption(casa::StorageOption::Option, int);
    };

    class SetupNewTable {
        public:
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption, casa::StorageOption const&);
            SetupNewTable(casa::String const&, casa::TableDesc const&, casa::Table::TableOption);
            ~SetupNewTable();
    };


    template<class T> class ScalarColumnDesc : public BaseColumnDesc {
        public:
            ScalarColumnDesc (const String& name);
            void tableDesc();
    };


    class RefRows {
        public:
            RefRows(casa::Vector<unsigned int> const&, bool, bool);
            ~RefRows();
            void convert() const;
            void fillNrows() const;
    };

    class BaseColumn {
        void putArrayColumn(void const*);
        void putColumnSlice(casa::Slicer const&, void const*);
        void putArrayColumnCells(casa::RefRows const&, void const*);
        void putColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void const*);
        void putSlice(unsigned int, casa::Slicer const&, void const*);
        void setShape(unsigned int, casa::IPosition const&);
        void setShape(unsigned int, casa::IPosition const&, casa::IPosition const&);
        void ndimColumn() const;
        void shapeColumn() const;
        void canAccessSlice(bool&) const;
        void canChangeShape() const;
        void getArrayColumn(void*) const;
        void getColumnSlice(casa::Slicer const&, void*) const;
        void getArrayColumnCells(casa::RefRows const&, void*) const;
        void getColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void*) const;
        void canAccessArrayColumn(bool&) const;
        void canAccessColumnSlice(bool&) const;
        void canAccessArrayColumnCells(bool&) const;
        void ndim(unsigned int) const;
        void shape(unsigned int) const;
        void getSlice(unsigned int, casa::Slicer const&, void*) const;
        void getScalar(unsigned int, int&) const;
    };

    class PlainColumn : public BaseColumn{
        public:
            virtual void keywordSet();
            void columnCache();
            void rwKeywordSet();
            void setShapeColumn(casa::IPosition const&);
            void setMaximumCacheSize(unsigned int);
            void bind(casa::DataManager*);
            PlainColumn(casa::BaseColumnDesc const*, casa::ColumnSet*);
            ~PlainColumn();
            void isWritable() const;
            void nrow() const;
            void isBound() const;
            void isStored() const;
    };

    template<class T> class ScalarColumnData : public PlainColumn{
    };

    class TableColumn{
        public:
            TableColumn(casa::Table const&, casa::String const&);
            TableColumn(casa::TableColumn const&);
            ~TableColumn();
            virtual void columnDesc() const;
            void throwNotWritable() const;
    };

    template<class T> class ScalarColumn{
        public:
            ScalarColumn(casa::Table const&, casa::String const&);
            void put(uInt rowid, T data);
    };

    class AipsError: public std::exception
    {
        public:
            enum Category {
                BOUNDARY, INITIALIZATION, INVALID_ARGUMENT, CONFORMANCE,
                ENVIRONMENT, SYSTEM, PERMISSION, GENERAL
            };
    };

    class TableError : public AipsError {
        public:
            TableError (Category c=GENERAL);
            TableError (const String& message,Category c=GENERAL);
            ~TableError () throw();
    };

    class TableInvDT : public TableError {
        public:
            TableInvDT (Category c=CONFORMANCE);
            TableInvDT (const String& columName,Category c=CONFORMANCE);
            ~TableInvDT () throw();
    };

    class TableTrace{
        public:
            void trace(int, casa::String const&, char);
            void trace(int, casa::String const&, char, casa::RefRows const&);
            void trace(int, casa::String const&, char, long long);
    };

    class DataManager{
        public:
            void createScalarColumn(casa::String const&, int, casa::String const&);
    };

    class FileLocker{
        public:
            enum LockType{Read, Write};
    };

    class ColumnSet{
        public:
            void doLock(casa::FileLocker::LockType, bool);
            void getDataManager(unsigned int) const;
    };


    class BaseCompare{
    };
    template<class T> class CountedPtr {
    };

    class ConcatTable{
    };

    class ConcatColumn: public BaseColumn{
        public:
            void initialize(unsigned int, unsigned int);
            void keywordSet();
            void rwKeywordSet();
            void columnCache();
            void freeIterBuf(void*&, void*&);
            void allocIterBuf(void*&, void*&, casa::CountedPtr<casa::BaseCompare>&);
            void putArrayColumn(void const*);
            void putColumnSlice(casa::Slicer const&, void const*);
            void putArrayColumnCells(casa::RefRows const&, void const*);
            void putColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void const*);
            void setMaximumCacheSize(unsigned int);
            void put(unsigned int, void const*);
            void putSlice(unsigned int, casa::Slicer const&, void const*);
            void setShape(unsigned int, casa::IPosition const&);
            void setShape(unsigned int, casa::IPosition const&, casa::IPosition const&);
            void ndimColumn() const;
            void shapeColumn() const;
            void canAccessSlice(bool&) const;
            void canChangeShape() const;
            void getArrayColumn(void*) const;
            void getColumnSlice(casa::Slicer const&, void*) const;
            void getArrayColumnCells(casa::RefRows const&, void*) const;
            void getColumnSliceCells(casa::RefRows const&, casa::Slicer const&, void*) const;
            void canAccessArrayColumn(bool&) const;
            void canAccessColumnSlice(bool&) const;
            void canAccessArrayColumnCells(bool&) const;
            void ndim(unsigned int) const;
            void shape(unsigned int) const;
            void getSlice(unsigned int, casa::Slicer const&, void*) const;
            void getScalar(unsigned int, int&) const;
            ConcatColumn(casa::BaseColumnDesc const*, casa::ConcatTable*);
            ~ConcatColumn();
            void isWritable() const;
            void canAccessScalarColumn(bool&) const;
            void canAccessScalarColumnCells(bool&) const;
            void get(unsigned int, void*) const;
            void nrow() const;
            void isStored() const;
            virtual void isDefined(unsigned int) const;
    };

    class TableLockData{
        public:
            void release(bool);
    };

    class TableConformanceError : public TableError{
        public:
            TableConformanceError(casa::String const&, casa::AipsError::Category);
            ~TableConformanceError() throw();
    };

    class TableArrayConformanceError : public TableError{
        public:
            TableArrayConformanceError(casa::String const&, casa::AipsError::Category);
            ~TableArrayConformanceError() throw();
    };

    class ConcatRows{
        public:
            void findRownr(unsigned int) const;
    };
}

#endif
