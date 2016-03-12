ifeq ($(VENDOR),cray)
	CC=cc -dynamic
else
	CC=mpic++
endif

CCFLAGS=
LDFLAGS=-lcasa_tables -lcasa_casa -lmxml -lshoreClient
TARGET=\
	   writeScalar \
	   writeArray \
	   readScalarColumn \
	   readArray \
	   readArrayColumn \
	   readArrayColumnSlice \

all: $(TARGET)

$(TARGET): $(TARGET:=.cc) $(SHORECLIENT_LIB)
	$(CC) $@.cc -o $@.exe $(CCFLAGS) $(LDFLAGS)

shoreClient:
	cd ..; make;

clean:
	rm -rf $(TARGET:=.exe) *.dSYM *.so

re: clean shoreClient all 
