ifeq ($(VENDOR),cray)
	CC=cc -dynamic
else
	CC=mpic++
endif

CCFLAGS=
LDFLAGS=-lcasa_tables -lcasa_casa -lshoreClient
TARGET=\
	   writeScalar \
	   writeScalarColumn \
	   writeArray \
	   writeArrayColumn \
	   readScalar \
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
	rm -rf *.exe *.dSYM *.so

re: clean shoreClient all 
