VERSION_MAJOR=2
VERSION_MIDDLE=0
VERSION_MINOR=1
TARGET_PREFIX=libcasa_tables
TARGET_SUFFIX=dylib

TARGET=$(TARGET_PREFIX).$(TARGET_SUFFIX)
TARGET_MAJOR=$(TARGET_PREFIX).$(VERSION_MAJOR).$(TARGET_SUFFIX)
TARGET_MIDDLE=$(TARGET_PREFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE).$(TARGET_SUFFIX)
TARGET_MINOR=$(TARGET_PREFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE).$(VERSION_MINOR).$(TARGET_SUFFIX)
SRC=casaShore.cc

PREFIX=$(CASACORE_HOME)

crack:$(TARGET)
ifdef CASACORE_HOME
	rm -rf $(CASACORE_HOME)/include/casacore/tables
	cp -r casaBullshit/tables $(CASACORE_HOME)/include/casacore
	rm -rf $(CASACORE_HOME)/lib/libcasa_tables* 
	rm -rf $(CASACORE_HOME)/lib/lib*stman* 
	cp $(TARGET_MINOR) $(CASACORE_HOME)/lib
	cd $(CASACORE_HOME)/lib
	ln -s $(TARGET_MINOR) $(CASACORE_HOME)/lib/$(TARGET_MAJOR)
	ln -s $(TARGET_MINOR) $(CASACORE_HOME)/lib/$(TARGET)
endif


$(TARGET):$(SRC)
	cp casaShore.h casaBullshit/tables/
	c++ -fPIC -lcasa_casa $(SRC) --shared -o $(TARGET_MINOR) -compatibility_version $(VERSION_MAJOR).0.0 -current_version $(VERSION_MAJOR).$(VERSION_MIDDLE).$(VERSION_MINOR)

clean:
	rm -rf $(TARGET_MINOR)

re:clean crack
