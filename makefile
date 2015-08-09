libcasa_shore:
	g++ casaBullshit.cc casaShore.cc --shared -o libcasa_shore.so
	g++ -g writeScalarSimple.cc -lcasa_casa -lcasa_shore -o writeScalar

clean:
	rm -rf libcasa_shore.so

