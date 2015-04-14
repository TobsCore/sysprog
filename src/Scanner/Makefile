# The Makefile for the Scanner of our simple compiler.
# It compiles either each file on its own, or the whole program.
# It contains a very simple clean method.
	
all:	main.o buffer.o automat.o scanner.o
		$(CXX) main.o buffer.o automat.o scanner.o -o run.o

main:		main.cpp
		$(CXX) -c main.cpp

scanner:	scanner.cpp
		$(CXX) -c scanner.cpp

automat:	automat.cpp
		$(CXX) -c automat.cpp

buffer:		buffer.cpp
		$(CXX) -c buffer.cpp

clean:
		rm *.o
