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
		filePath = "./test.txt";
	}

	cout << filePath << endl;

	Buffer* buf = new Buffer(filePath);
	while (buf->hasNext()) {
		cout << buf->getChar();
	}
	return 0;
}



