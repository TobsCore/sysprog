#ifndef O_DIRECT
#define O_DIRECT 0
#endif

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//zum testen
#include <iostream>

#ifndef BUFFER
#define BUFFER

static const int chunkSize = 1024;


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
    char eof;
    bool isFinished;
    bool noRefill;
    bool isLeft;
    int bytesRead;
    int byteLeft;
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

#endif /* BUFFER */
