lib:
	(cd Core && make libcore.so)
	mkdir -p Lib
	cp Core/libcore.so Lib/

all: lib
	