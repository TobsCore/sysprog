#ifndef SCANNER
#define SCANNER
#include "scanner.h"
#endif

#ifndef SYMTYPE
#define SYMTYPE
#include "../../SymbolType/symboltype.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

Scanner::Scanner(char* filePath) {

	this->automat = new Automat();
	this->buffer = new Buffer(filePath);
}

Token Scanner::nextToken() {
	Token* nextToken = new Token();

	if (!buffer->hasNext()) {
		nextToken->setType(FILE_END);
		return *nextToken;
	}

	Signtype symbol;
	do {
		char nextChar = buffer->getChar();
		symbol = automat->checkExpression(nextChar);
	} while(symbol == NEXTCHAR);
	nextToken->setType(symbol);
	return *nextToken;
}


int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Missing argument." << endl;
	} else {
		char* filePath = argv[1];
		Scanner* sc = new Scanner(filePath);

		Token token;
		while (!token.isEOF()) {
			token = sc->nextToken();
			cout << token.getType() << endl;
		}
	}
	return 0;
}
