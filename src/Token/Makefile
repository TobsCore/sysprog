all:	token.o testToken.o
	$(CXX) -o testToken.out token.o testToken.o

token:	token.cpp
	$(CXX) -c token.cpp

testtoken:	testtoken.cpp
	$(CXX) -c testToken.cpp

clean:
	rm *.o *.out
