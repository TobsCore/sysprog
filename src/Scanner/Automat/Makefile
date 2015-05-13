all:	automatTest.o automat.o
	$(CXX) -o AutomatTest.out automatTest.o automat.o

automat:	automat.cpp
	$(CXX) -c automat.cpp

automatTest:	automatTest.cpp
	$(CXX) -c automatTest.cpp

clean:
	rm *.o *.out
