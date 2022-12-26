compile:
	cmake -j -B build -S .
	$(MAKE) -C build

run:
	./build/src/prolog-test

clean:
	rm -rf build