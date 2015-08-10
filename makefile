TARGET=libcasa_tables.so
SRC=casaBullshit.cc casaShore.cc

crack:$(TARGET)
ifdef CASACORE_HOME
	rm -f $(CASACORE_HOME)/lib/libcasa_tables*
	cp $(TARGET) $(CASACORE_HOME)/lib/libcasa_tables.so
	cp -r casacore $(CASACORE_HOME)/include
endif

install:$(TARGET)
ifdef CASACORE_HOME
	cp $(TARGET) $(CASACORE_HOME)/lib
	cp -r casacore $(CASACORE_HOME)/include
endif

$(TARGET):$(SRC)
	cp casaShore.h casacore/tables/
	g++ casaBullshit.cc casaShore.cc --shared -o $(TARGET)

clean:
	rm -rf $(TARGET) writeScalar *.dSYM

re:clean crack
