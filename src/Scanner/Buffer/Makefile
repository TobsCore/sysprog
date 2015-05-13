all:	Buffer.o main
	$(CXX) -o testBuffer.out Buffer.o main.o

buffer:	Buffer.cpp
	$(CXX) -c Buffer.cpp
	
main:	main.cpp
	$(CXX) -c main.cpp

clean:
	rm *.o
