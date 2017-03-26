all:	container.o

test:	container.o testcontainer.o
	$(CXX) -o TestContainer.out container.o testcontainer.o

container:	container.cpp
	$(CXX) -c container.cpp

testcontainer:	testcontainer.cpp
	$(CXX) -c testcontainer.cpp

clean:
	rm *.o *.out
