# The Makefile for the Scanner of our simple compiler.
# It compiles either each file on its own, or the whole program.
# It contains a very simple clean method.
	
all:	main.o buf auto scan
		$(CXX) main.o Buffer/buffer.o Automat/automat.o Scanner/scanner.o -o run.o

main:		main.cpp
		$(CXX) -c main.cpp

buf:
	make -C Buffer

scan:
	make -C Scanner

auto:
	make -C Automat

clean:
	rm *.o
	rm Automat/*.o
	rm Buffer/*.o
	rm Scanner/*.o
	rm Token/*.o
