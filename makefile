lib:
	(cd Core && make libcore.so)
	cp Core/libcore.so Lib/

test-clean:
	(cd Test && make clean)

test:
	rm Test/main
	(cd Test && make main)

test-run: test 
	@echo "Running Game..."
	(cd Test)
	./Test/main