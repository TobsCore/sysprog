#include "Buffer.h"

Buffer::Buffer(char* source) {
	bufferLength = 1024;

	leftBuffer = new char[bufferLength + 1];
	rightBuffer = new char[bufferLength + 1];

//Speicher für leftBuffer und rightBuffer holen.
	posix_memalign((void**) &(this->leftBuffer), 1024, bufferLength);
	posix_memalign((void**) &(this->rightBuffer), 1024, bufferLength);

	fdRead = /*fdWrite =*/ 0; //fd = FileDescriptor = nicht negativer Integer.
	baseLeft = current = next = &leftBuffer[0]; //base ist immer neuer anfang von Buffer
	baseRight = &rightBuffer[0];
	isLeft = true;
	eof = 0;
	isFileOpen = isFinished = false;
	sourceFile = source;
	openFile();
	fillBuffer();
}

Buffer::~Buffer() { //dekonstruktor?
	delete leftBuffer;
	delete rightBuffer;
}

char Buffer::getChar() {
	current = next; //nimm das zuletzt als nächstes Zeichen gesetzte, als neues aktuelles Zeichen.

	if (isFinished) {
		cout << "FINISHED";
	}

	if(*current == eof){ //Test ob Datei zu ende.
		isFinished = true;
		close(fdRead);
		return *current;
	}

	if (current == baseRight + bufferLength - 1) { //wenn wir uns im letzten Zeichen befinden dann leftBuffer neu befüllen
		isLeft = true;
		fillBuffer(); //leftBuffer neu befüllen
		next = baseLeft;
		return *current;
	}
	if (current == baseLeft + bufferLength - 1) { //wenn wir uns im letzten Zeichen befinden dann rightBuffer befüllen
		isLeft = false;
		fillBuffer(); //rightBuffer neu befüllen
		next = baseRight;
		return *current;
	}
	next++; //Aktuelles Zeichen befindet sich irgendwo mitten im Buffer
	return *current;
	}

void Buffer::ungetChar(int count) {
	for(int i = 0;i>=count;i++){
	if (current == baseRight) { //current steht am anfang von rightBuffer
		next = &leftBuffer[bufferLength - 1];
		isLeft = true;
	} else if (current == baseLeft) { //current steht am anfang von leftBuffer
		next = &rightBuffer[bufferLength - 1];
		isLeft = false;
	} else { //current steht irgendwo in der mitte
		next--;
	}
	}
	current = next;
}

void Buffer::openFile() {
	fdRead = open(sourceFile, O_DIRECT);
	if(fdRead != -1){	//öffnen der Datei hat geklappt.
		isFileOpen = true; //dann setze isFileOpen auf true
	} else {
		cout << "Error! File " << sourceFile << " couldn't be opened";
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
	if (isLeft) {
		read(fdRead, baseLeft, 1024);
	} else {
		read(fdRead, baseRight, 1024);
	}
}

//Bekommt einzelne Zeichen, speichert sie zwischen und schreibt sie wenn das Array voll ist in die Datei
/*void Buffer::putChar(char c){
	current = next;

	if(!isFileOpen){
		createFile();
	}

	if(c == eof){ //Letztes Zeiches
		*current = c; //Rest in Datei schreiben
		if(isLeft){ //Schauen das Reihenfolge beim schreiben stimmt.
			for(int i = 0; current != (baseLeft + (bufferLength - 1 - i)); i++){ //rest des Speichers mit Leerzeichen füllen
				*(baseLeft + (bufferLength - 1 - i)) = 32;
			}
			if(*(baseRight + (bufferLength - 1)) != 0){
				write(fdWrite, baseRight, bufferLength);
			}
			write(fdWrite, baseLeft, bufferLength);
		}
		else{
			for(int i = 0; current != (baseRight + (bufferLength - 1 - i)); i++){ //rest des Speichers mit Leerzeichen füllen
				*(baseRight + (bufferLength - 1 - i)) = 32;
			}
			if(*(baseLeft + (bufferLength -1)) != 0 ){
				write(fdWrite, baseLeft, bufferLength);
			}
			write(fdWrite, baseRight, bufferLength);
		}
		cout << endl << "Close File" << endl;
		if(close(fdWrite) == -1){
			cout << "Fehler beim schließen der Datei";
		}
	}
	else{
		//Fülle so lange linkes Array bis es voll ist. Danach das Rechte. Ist das voll wird das Linke geschrieben usw.
		if(current == baseLeft + (bufferLength -1)){
			if(*baseRight != 0 ){ //das kein leeres Array in Datei geschrieben wird
				write(fdWrite, baseRight, bufferLength);
			}
			cout << "Linke Seite voll" << endl;
			next = baseRight;
			isLeft = false;
			*current = c;
			cout << *current;
			return;
		}
		if(current == baseRight + (bufferLength -1)){
			if(*baseLeft != 0){ //das kein leeres Array in Datei geschrieben wird
				write(fdWrite, baseLeft, bufferLength);
			}
			cout << "Rechte Seite voll" << endl;
			next = baseLeft;
			isLeft = true;
			*current = c;
			cout << *current;
			return;
		}
		next++;
		*current = c;
		cout << *current;
	}
}*/

bool Buffer::hasNext(){
	return !isFinished;
}

void Buffer::closeFiles(){ //schließt die geöffneten Dateien wieder
	close(fdRead);
	//close(fdWrite);
}
//current wird übergeben
