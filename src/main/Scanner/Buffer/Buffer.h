#ifndef O_DIRECT
#define O_DIRECT 0
#endif

#ifndef BUFFER_H_
#define BUFFER_H_

static const int chunkSize = 1024;

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
    char *leftBuffer;
    char *rightBuffer;
    const char *sourceFile;
    int fdRead;
    //int fdWrite;
    int eof;
    bool isFinished;
    bool noRefill;
    bool isLeft;
    bool isFileOpen;
    unsigned int bufferLength;

    void fillBuffer();

    //void createFile();
    void openFile();

public:
    Buffer(const char *source);

    virtual ~Buffer();

    char getChar();

    void ungetChar(int);

    //void putChar(char c);
    bool hasNext();

    void closeFiles();
};

#endif /* BUFFER_H_ */
