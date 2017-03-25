all:	scanner.o ../../Token/token.o ../Buffer/Buffer.o ../Automat/automat.o
	$(CXX) -o scanner.out scanner.o ../../Token/token.o ../Buffer/Buffer.o ../Automat/automat.o

scanner:	scanner.cpp
	$(CXX) -c scanner.cpp
	
Buffer:	Buffer.cpp
	$(CXX) -c Buffer.cpp
	
automat:	automat.cpp
	$(CXX) -c automat.cpp
	
token:	token.cpp
	$(CXX) -c tokens.cpp

clean:
	rm *.o *.out
