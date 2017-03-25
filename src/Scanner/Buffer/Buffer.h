#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//zum testen
#include <iostream>
using namespace std;

class Buffer {

private:
	char *baseLeft;
	char *baseRight;
	char *next;
	char *current;
	char* leftBuffer;
	char* rightBuffer;
	char* sourceFile;
	int fdRead;
	//int fdWrite;
	int eof;
	bool isFinished;
	bool isLeft;
	bool isFileOpen;
	unsigned int bufferLength;
	void fillBuffer();
	//void createFile();
	void openFile();

public:
	Buffer(char* source);
	virtual ~Buffer();
	char getChar();
	void ungetChar(int);
	//void putChar(char c);
	bool hasNext();
	void closeFiles();

};

#endif /* BUFFER_H_ */
