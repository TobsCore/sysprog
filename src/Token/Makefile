all:	token.o

test:	token.o testtoken.o
	$(CXX) -o TestToken.out token.o testtoken.o

token:	token.cpp
	$(CXX) -c token.cpp

testtoken:	testtoken.cpp
	$(CXX) -c testtoken.cpp

clean:
	rm *.o *.out
