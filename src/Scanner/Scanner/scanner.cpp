#ifndef SCANNER
#define SCANNER
#include "scanner.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

Scanner::Scanner() {
	currentRow = 1;
	currentColumn = 1;

	this->automat = new Automat();

	// TODO: Fix filepath, to take an argumet and use this argument as the new filepath
	char* filePath = "/home/tobscore/Documents/sysprog/src/Scanner/Scanner/scanner.h";
	this->buffer = new Buffer(filePath);
}


int main(int argc, char** argv) {

	Scanner* sc = new Scanner();
	return 0;
}
