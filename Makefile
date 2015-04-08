docu:
	make -C Documentation

clean:
	make clean -C Documentation
	make clean -C src/Scanner
