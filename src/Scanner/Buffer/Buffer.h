/*
 * Buffer.h
 *
 *  Created on: 07.05.2015
 *      Author: patrick
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {

public:
    Buffer(char* filePath);
    ~Buffer();
    char getChar();
    void ungetChar();

private:
    char* filePath;
    int bufferSize;
    char* buffer1;
    char* buffer2;
    short currentBuffer;
    char currentCharacter;
    char nextCharacter;
    char* pointerBuffer1;
    char* pointerBuffer2;
    int bufferCounter;
    int bufferCounter2;
    int myFile;
    int endOfFile;
    int read_in;



};



#endif /* BUFFER_H_ */
