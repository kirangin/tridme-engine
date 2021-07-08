lib:
	(cd Core && make libcore.so)
	cp Core/libcore.so Lib/

test:
	(cd Test && make main)

test-clean:
	(cd Test && make clean)

test-run: test 
	@echo "Running Game..."
	(cd Test)
	./Test/main