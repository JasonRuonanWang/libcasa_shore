libcasa_shore:
	cp casaShore.h casacore/tables/
	g++ -fPIC casaBullshit.cc casaShore.cc --shared -o libcasa_shore.so
	g++ -fPIC -g writeScalar.cc -lcasa_casa -lcasa_shore -o writeScalar

clean:
	rm -rf libcasa_shore.so writeScalar *.dSYM

