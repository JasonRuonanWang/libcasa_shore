VERSION_MAJOR=916
VERSION_MIDDLE=229
VERSION_MINOR=141

SRC=casaShore.cc
TARGET_PREFIX=libcasa_tables

OS := $(shell uname)
ifeq ($(OS), Darwin)
	TARGET_SUFFIX=dylib
	TARGET=$(TARGET_PREFIX).$(TARGET_SUFFIX)
	TARGET_MAJOR=$(TARGET_PREFIX).$(VERSION_MAJOR).$(TARGET_SUFFIX)
	TARGET_MIDDLE=$(TARGET_PREFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE).$(TARGET_SUFFIX)
	TARGET_MINOR=$(TARGET_PREFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE).$(VERSION_MINOR).$(TARGET_SUFFIX)
else
	TARGET_PREFIX=libcasa_tables
	TARGET_SUFFIX=so
	TARGET=$(TARGET_PREFIX).$(TARGET_SUFFIX)
	TARGET_MAJOR=$(TARGET_PREFIX).$(TARGET_SUFFIX).$(VERSION_MAJOR)
	TARGET_MIDDLE=$(TARGET_PREFIX).$(TARGET_SUFFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE)
	TARGET_MINOR=$(TARGET_PREFIX).$(TARGET_SUFFIX).$(VERSION_MAJOR).$(VERSION_MIDDLE).$(VERSION_MINOR)
endif



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
ifeq ($(OS), Darwin)
	c++ -fPIC -lcasa_casa -lShoreClient $(SRC) --shared -o $(TARGET_MINOR) -compatibility_version $(VERSION_MAJOR).0.0 -current_version $(VERSION_MAJOR).$(VERSION_MIDDLE).$(VERSION_MINOR)
else
	c++ -fPIC -lcasa_casa -lShoreClient $(SRC) --shared -o $(TARGET_MINOR) -Wl,-soname,$(TARGET_MAJOR)
endif

clean:
	rm -rf *.dylib *.so

re:clean crack
