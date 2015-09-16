TARGET=libcasa_tables.so
SRC=casaShore.cc

PREFIX=$(CASACORE_HOME)

crack:$(TARGET)
ifdef CASACORE_HOME
	rm -rf $(CASACORE_HOME)/include/casacore/tables
	rm -rf $(CASACORE_HOME)/lib/libcasa_tables* 
	rm -rf $(CASACORE_HOME)/lib/lib*stman* 
	cp $(TARGET) $(CASACORE_HOME)/lib/libcasa_tables.so
	cp -r casaBullshit/tables $(CASACORE_HOME)/include/casacore
endif


$(TARGET):$(SRC)
	cp casaShore.h casaBullshit/tables/
	c++ -fPIC $(SRC) --shared -o $(TARGET)

clean:
	rm -rf $(TARGET)

re:clean crack
