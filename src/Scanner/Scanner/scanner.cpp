#ifndef SCANNER
#define SCANNER
#include "scanner.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

Scanner::Scanner(char* filePath) {

	this->automat = new Automat();
	this->buffer = new Buffer(filePath);

	while (buffer->hasNext()) {
		cout << buffer->getChar();
	}
}


int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Missing argument." << endl;
	} else {
		char* filePath = argv[1];
		Scanner* sc = new Scanner(filePath);
	}
	return 0;
}
