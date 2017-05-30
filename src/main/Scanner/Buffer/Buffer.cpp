#include "Buffer.h"

Buffer::Buffer(const char *source) {
    bufferLength = chunkSize;

//Speicher für leftBuffer und rightBuffer holen.
    posix_memalign((void **) &(this->leftBuffer), chunkSize, bufferLength);
    posix_memalign((void **) &(this->rightBuffer), chunkSize, bufferLength);

    fdRead = /*fdWrite =*/ 0; //fd = FileDescriptor = nicht negativer Integer.
    baseLeft = current = next = &leftBuffer[0]; //base ist immer neuer anfang von Buffer
    baseRight = &rightBuffer[0];
    isLeft = true;
    noRefill = false;

    bytesRead = 0;
    byteLeft = chunkSize;
    eof = 0;

    isFileOpen = isFinished = false;
    sourceFile = source;
    openFile();
    fillBuffer();
}

Buffer::~Buffer() {
    closeFiles();
    free(leftBuffer);
    free(rightBuffer);
}

char Buffer::getChar() {
    current = next; //nimm das zuletzt als nächstes Zeichen gesetzte, als neues aktuelles Zeichen.
    if (bytesRead < chunkSize) {
        byteLeft--;
    }

    if (*current == eof || byteLeft == 0) { //Test ob Datei zu ende.
        isFinished = true;
        close(fdRead);
        return eof;
    }

    if (current == baseRight + bufferLength - 1) {
        //wenn wir uns im letzten Zeichen befinden dann leftBuffer neu befüllen
        isLeft = true;
        fillBuffer(); //leftBuffer neu befüllen
        next = baseLeft;
        return *current;
    }
    if (current == baseLeft + bufferLength - 1) {
        //wenn wir uns im letzten Zeichen befinden dann rightBuffer befüllen
        isLeft = false;
        fillBuffer(); //rightBuffer neu befüllen
        next = baseRight;
        return *current;
    }
    next++; //Aktuelles Zeichen befindet sich irgendwo mitten im Buffer
    return *current;
}

void Buffer::ungetChar(int count) {
    for (int i = 0; i < count; i++) {
        if (next == baseRight) { //current steht am anfang von rightBuffer
            next = &leftBuffer[bufferLength - 1];
            noRefill = true;
            isLeft = true;
        } else if (next == baseLeft) { //current steht am anfang von leftBuffer
            next = &rightBuffer[bufferLength - 1];
            noRefill = true;
            isLeft = false;
        } else { //current steht irgendwo in der mitte
            next--;
            if (bytesRead < chunkSize) {
                byteLeft++;
            }
        }
    }
    current = next;
}

void Buffer::openFile() {
    fdRead = open(sourceFile, O_DIRECT);
    if (fdRead != -1) {    //öffnen der Datei hat geklappt.
        isFileOpen = true; //dann setze isFileOpen auf true
    } else {
        throw std::runtime_error("Input file couldn't be opened");
    }
}

/*void Buffer::createFile() {
	cout << endl << "in Buffer::createFile" << endl;
	fdWrite = creat(sourceFile, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); //warum nicht create??
	if(fdWrite != -1){
		isFileOpen = true;
	}else{
		cout << endl << "!!! FEHLER BEIM ERSTELLEN DER DATEI FD: " << fdWrite << " !!!" << endl;
	}
}*/

void Buffer::fillBuffer() {
    if (!noRefill) {
        if (isLeft) {
            bytesRead = read(fdRead, baseLeft, chunkSize);
        } else {
            bytesRead = read(fdRead, baseRight, chunkSize);
        }

        // If 0 bytes are read, this means the end of file has been reached.
        if (bytesRead == 0) {
            *current = '\0';
        } else if (bytesRead < chunkSize) {
            byteLeft = bytesRead + 1;
        }
    } else {
        noRefill = false;
    }
}

bool Buffer::hasNext() {
    return !isFinished;
}

void Buffer::closeFiles() { //schließt die geöffneten Dateien wieder
    close(fdRead);
    //close(fdWrite);
}
