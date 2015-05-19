all:	scanner.o ../../Token/token.o ../Buffer/Buffer.o ../Automat/automat.o
	$(CXX) -o scanner.out scanner.o ../../Token/token.o ../Buffer/Buffer.o ../Automat/automat.o

scanner:	scanner.cpp
	$(CXX) -c scanner.cpp

clean:
	rm *.o *.out
