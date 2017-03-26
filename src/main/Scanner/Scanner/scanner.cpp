#include "scanner.h"

Scanner::Scanner(char const *filePath) {

	this->automat = new Automat();
	this->buffer = new Buffer(filePath);
}

Token Scanner::nextToken() {
	Token* nextToken = new Token();

	// If no other characters can be read, return and EOF-Token. This can be used to stop the calling loop.
	if (!buffer->hasNext()) {
		nextToken->setType(FILE_END);
		return *nextToken;
	}

	Signtype symbol;
	do {
		char nextChar = buffer->getChar();
		symbol = automat->checkExpression(nextChar);
	} while (symbol == NEXTCHAR && buffer->hasNext());

	// If a symbol has a NEXTCHAR, this means that the loop has quit because there's no other character in the buffer.
	// This equals to an EOF, which should be returned.a
	if (symbol == NEXTCHAR) {
		symbol = FILE_END;
	}

	nextToken->setType(symbol);
	return *nextToken;
}