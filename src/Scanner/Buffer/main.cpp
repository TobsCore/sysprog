#ifndef IO
#define IO
#include <iostream>
#endif

#ifndef BUFFER
#define BUFFER
#include "Buffer.h"
#endif

using namespace std;

int main(int argc, char** argv) {

	// Either get a path via arguments, or just simply use the test.txt
	char* filePath;
	if(argc == 2) {
		filePath = (char*)argv[1];
	} else {
		filePath = "./testProgramm.txt";
	}

	cout << filePath << endl;

	Buffer* joo = new Buffer(filePath);
	for (int i = 0; i< 128; i++)
	{
	char c = joo->getChar();
	cout << "mein char: " << i << ": " << c << endl;
	}
	return 0;
}



