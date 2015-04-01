all:		simple

simple:		main.o buffer.o automat.o scanner.o
		g++ main.o buffer.o automat.o scanner.o -o program.o

main:		main.cpp
		g++ -c main.o

scanner:	scanner.cpp
		g++ -c scanner.cpp

automat:	automat.cpp
		g++ -c automat.cpp

symtab:		symtab.cpp
		g++ -c symtab.cpp

buffer:		buffer.cpp
		g++ -c buffer.cpp

clean:
		rm *.o