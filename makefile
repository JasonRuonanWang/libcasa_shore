TARGET=libcasa_tables.so
SRC=casaBullshit.cc casaShore.cc

PREFIX=$(CASACORE_HOME)

crack:$(TARGET)
ifdef CASACORE_HOME
	rm -rf $(CASACORE_HOME)/include/casacore/tables
	rm -rf $(CASACORE_HOME)/lib/libcasa_tables* 
	rm -rf $(CASACORE_HOME)/lib/lib*stman* 
	cp $(TARGET) $(CASACORE_HOME)/lib/libcasa_tables.so
	cp -r casacore $(CASACORE_HOME)/include
endif

install:$(TARGET)
ifdef PREFIX
	cp $(TARGET) $(PREFIX)/lib
	cp -r casacore $(PREFIX)/include
endif

$(TARGET):$(SRC)
	cp casaShore.h casacore/tables/
	c++ casaBullshit.cc casaShore.cc --shared -o $(TARGET)

clean:
	rm -rf $(TARGET)

re:clean crack
