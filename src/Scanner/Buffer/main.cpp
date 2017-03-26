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
	char const *filePath = (argc == 2) ? argv[1] : "./test.txt";

	cout << filePath << endl;

	Buffer* buf = new Buffer(filePath);
	while (buf->hasNext()) {
		cout << buf->getChar();
	}
	return 0;
}



