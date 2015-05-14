#ifndef BUFFER
#define BUFFER
#include "Buffer.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

//Konstruktor für Buffer, der Pfad der Textdatei wird als Parameter
//übergeben
Buffer::Buffer(char* filePath){

	this->filePath = filePath;
	bufferSize = 512;					//512 Byte = 512 Chars
	int myError1, myError2;				//ErrorInts für posix_memalign
	buffer1 = new char[bufferSize];		//buffer 1 ist 512 Byte groß
	buffer2 = new char[bufferSize];		//buffer 2 ist 512 Byte groß

	/**
	 * Allokieren des Speichers (512 Byte).
	 * Alignment: 512 (Es können nur Speicheradressen allokiert werden,
	 * die ein Vielfaches von 512 bilden. Dies ist nötig für das O_DIRECT
	 * Flag.)
	 * Ein Pointer auf den allokierten Speicher wird an buffer1 bzw. buffer2
	 * übergeben. Für die Funktion muss &pointer zu (void**) gecastet werden
	 *
	 * myError muss 0 sein, damit alles Fehlerfrei verlief.
	 */
	myError1 = posix_memalign((void**) &buffer1, bufferSize, bufferSize);
	myError2 = posix_memalign((void**) &buffer2, bufferSize, bufferSize);



	pointerBuffer1 = buffer1; //ein Pointer auf buffer1 (gleich: &buffer1[0])
	pointerBuffer2 = buffer2;	// ein Pointer auf buffer2 (gleich: &buffer2[0])

	currentCharacter = buffer1[0]; //wird noch nicht benötigt
	nextCharacter = buffer1[0];

	currentBuffer = 1;	//der aktuelle Buffer
	bufferCounter = 0;	//Zeichencounter für Buffer1 (geht bis 512)
	bufferCounter2 = 0;	//Zeichencounter für Buffer2

	/**
	 * Öffnen des Files mit setzen des O_DIRECT flags.
	 * Gibt es beim öffnen einen Fehler wird -1 in myile geschrieben
	 */
	myFile = open (filePath, O_DIRECT);
		if (myFile == -1){
			cout << "Unable to open " << filePath;
		}

		/*
		 *War das Öffnen erfolgreich, kann gelesen werden
		 *(vorrausgesetzt der Speicher wurde erfolgreich allokiert)
		 */
		else{

			if(myError1 == 0 && myError2 == 0){

				read_in = read (myFile,buffer1,bufferSize); //es werden "Buffersize" Zeichen gelesen

				if (read_in < 512){	//Falls weniger als 512 Zeichen eingelesen wurden, ist das File zu Ende.

					endOfFile = 1;
				}
			}

			else{
				cout << "Unable to allocate memory" << endl;
			}
		}


}

/*Der mit Posix_Memalign allokierte Speicher wird im Destruktor
 *wieder freigegeben
 */
Buffer::~Buffer()
{
	free(buffer1);
	free(buffer2);
	}

char Buffer::getChar(){

/**
 * Falls der bufferCounter des ersten Buffers auf 512 ist,
 * wird auf den zweiten Buffer gewechselt. Der erste Buffer wird jedoch
 * noch nicht überschrieben.
 */
	if(bufferCounter == 512)
	{
		bufferCounter = 0;
		read_in = read (myFile,buffer2,bufferSize);
		pointerBuffer2 = buffer2;

		if (read_in < 512){

			endOfFile = 1;
		}

		currentBuffer = 2;
	}

	/**
	 * Falls der bufferCounter des zweiten Buffers auf 512 ist,
	 * wird wieder auf den ersten Buffer gewechselt
	 */
	if(bufferCounter2 == 512){

		bufferCounter2 = 0;
		read_in = read (myFile,buffer1,bufferSize);
		pointerBuffer1 = buffer1;

		if (read_in < 512){

			endOfFile = 1;
		}

		currentBuffer = 1;
	}

	//Falls der erste Buffer arbeitet
	if(currentBuffer == 1 && bufferCounter <= 512){
	bufferCounter++;

		//Falls das File noch nicht zu Ende ist
		if(*pointerBuffer1 != '\0'){
			return *pointerBuffer1++;
		}

		else{
		currentBuffer = 0;
		return '\0';
		}
	}

	/**
	 * Falls der zweite Buffer gerade arbeitet
	 */
	else if (currentBuffer == 2 && bufferCounter2 <=512){
		bufferCounter2++;

		//Prüfen ob File zu Ende ist
		if(*pointerBuffer2 != '\0'){
		return *pointerBuffer2++;
		}

		else{
			currentBuffer = 0;
			return '\0';
		}
	}

	/**
	 * Falls kein Buffer arbeitet (das File ist fertig),
	 * wird ein 0 Terminator zurückgegeben
	 */
	else {
		return '\0';
	}

}

void Buffer::ungetChar(){


}


