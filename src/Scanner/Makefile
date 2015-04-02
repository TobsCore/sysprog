# The Makefile for the Scanner of our simple compiler.
# It compiles either each file on its own, or the whole program.
# It contains a very simple clean method.

all:		simple

simple:		main.o buffer.o automat.o scanner.o
		$(CXX) main.o buffer.o automat.o scanner.o -o program.o

main:		main.cpp
		$(CXX) -c main.o

scanner:	scanner.cpp
		$(CXX) -c scanner.cpp

automat:	automat.cpp
		$(CXX) -c automat.cpp

symtab:		symtab.cpp
		$(CXX) -c symtab.cpp

buffer:		buffer.cpp
		$(CXX) -c buffer.cpp

clean:
		rm *.o
