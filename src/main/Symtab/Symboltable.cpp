/*
 * Symboltable.cpp
 *
 *  Created on: 02.05.2015
 *      Author: holger
 */


#include <iostream>
#include <cstdlib>

#include "Symboltable.h"
#include "Information.h"
#include "../SymbolType/symboltype.h"
#include "SymbolItem.h"

using namespace std;

Symboltable::Symboltable(){
	for(int i = 0; i < tableSize; i++){
		this->hashTable[i] = NULL;
	}
	this->stringTable = new StringItem;
	this->ptrStringMemory = stringTable->stringMemory;
	this->stringTable->next = NULL;
	this->counterStringMemory = 0;
}


int Symboltable::length(const char* lexem) {
	int i = 0;
	while(lexem[i] != '\0'){
		i++;
	}
	return i;
}


bool Symboltable::compare(const char* lexem1, const char* lexem2) {
	int i = 0;
	while(lexem1[i] != '\0'){
		if(lexem1[i] != lexem2[i]){
			return false;
		}
		i++;
	}
	if(lexem2[i] != '\0'){
		return false;
	}
	return true;
}


int Symboltable::hashcode(const char* lexem, int length){
	int hashCode = (int) ( 16 * lexem[0] + 8 * lexem[length - 1] + length);
	return hashCode % tableSize;

}


SymbolItem* Symboltable::insert(const char* lexem){
	// Erstelle einen Pointer für das Element
	SymbolItem* ptrItem;

	// Berechne die Hashadresse, wo das neue Element
	// gespeichert wird
	int lexemLength = length(lexem);
	int hashAdress = hashcode(lexem, lexemLength);

	cout << "Einfügen in Hashadresse : " << hashAdress << endl;

	// Pointer zeigt auf die errechnete Hashadresse
	// in der Hashtabelle
	ptrItem = hashTable[hashAdress];

	// Suche freien Platz auf der errechnete Hashadresse
	// und schaue ob das Element schon gibt
	while(ptrItem != NULL){
		if(compare(ptrItem->lexem, lexem)){
			cout << "Das Element gibt es schon!" << endl;
			return ptrItem;
		}
		ptrItem = ptrItem->next;
	}

	// Speicher für neues Element bereitstellen und ausgeben
	// wenn es keinen mehr gibt
	ptrItem = (SymbolItem*) malloc(sizeof(SymbolItem) + sizeof(Information));

	if(ptrItem == NULL){
		cout << "Kein Speicher für neues Element vorhanden" << endl;
		return NULL;
	}


	// Fügt ale Werte in das neues Element ein
	ptrItem->infoContainer.setName(lexem);
	ptrItem->lexem = insertStringTable(lexem);

	// Fügt neues Element in die Hashtabelle ein
	ptrItem->next = hashTable[hashAdress];
	hashTable[hashAdress] = ptrItem;
	//delete ptrItem;

	return ptrItem;
}

char* Symboltable::insertStringTable(const char* lexem){
	// Erstelle ein Pointer auf Stringtabelle und gehe
	// zum letzten Element
	StringItem* ptrStringItem = stringTable;
	while(ptrStringItem->next != NULL){
		ptrStringItem = ptrStringItem->next;
	}

	// Findet vor dem einfügen heraus, ob
	// ein neues Element angelegt werden muss
	int length = this->length(lexem);
	if(( length + counterStringMemory) >= 1024){

		// Speicher für neues Element bereitstellen
		// und ausgeben wenn es keinen mehr gibt
		StringItem* newStringItem = (StringItem*) malloc(sizeof(StringItem*));
		if(newStringItem == NULL){
			cout << "Kein Speicher für neues Element vorhanden" << endl;
			return NULL;
		}
		// Neues Element bekommt Werte und wird
		// an Stringtabelle hinzugefügt
		newStringItem->next = NULL;
		stringTable->next = newStringItem;

		// Zähler und Pointer werden auf das
		// neue Element angepasst
		counterStringMemory = 0;
		ptrStringMemory = newStringItem->stringMemory;
	}

	// Pointer von String wird auf die nächste
	// freie Stelle geführt, um das neue Lexem
	// zu speichern
	ptrStringMemory = &(ptrStringMemory[counterStringMemory]);

	// Lexem wird in String hinzugefügt und Zähler
	// wird aktualisiert
	int i = 0;
	while(lexem[i] != '\0'){
		ptrStringMemory[counterStringMemory] = lexem[i];
		counterStringMemory++;
		i++;
	}
	ptrStringMemory[i] = '\0';
	counterStringMemory++;

	// Rückgabe von der Position des neuen Wortes
	return ptrStringMemory;
}

SymbolItem* Symboltable::search(const char* lexem){
	// Erstelle einen Pointer für das Element
	SymbolItem* ptrItem;

	// Berechne die Hashadresse, wo das Element
	// gespeichert wurde
	int lexemLength = length(lexem);
	int hashAdress = hashcode(lexem, lexemLength);
	cout << "Suche in Hashadresse : " << hashAdress << endl;

	// Pointer zeigt auf die errechnete Hashadresse
	// in der Hashtabelle
	ptrItem = hashTable[hashAdress];

	// Suche Element auf der errechnete Hashadresse
	while(ptrItem != NULL){
		if(compare(ptrItem->lexem, lexem)){
			cout 	<< "---------------------------" << endl;
			cout	<< "Das Element gibt es unter Hashadresse " << hashAdress << endl;
			cout	<< "Hashelement: " << ptrItem << endl;
			cout << "Type: " << ptrItem->infoContainer.getType() << endl;
			cout << "Name: " << ptrItem->infoContainer.getName() << endl;
			cout << "Keyword: " << ptrItem->infoContainer.getKeyword() << endl;
			int j = 0;
			cout << "Lexem: ";
			while(ptrItem->lexem[j] != '\0' && j < 5){
				cout << ptrItem->lexem[j];
				j++;
			}
			return ptrItem;
		}
		ptrItem = ptrItem->next;
	}
	return NULL;

}


void Symboltable::view(){
	for(int i = 0; i < tableSize; i++){
		SymbolItem* testItem = hashTable[i];
		while(testItem != NULL){
			cout << "Infocontainer in Hashelement " << testItem << " im Index " << i <<endl;
			testItem->infoContainer.viewInformation();

			cout << "Lexem in Hashelement " << testItem << " im Index " << i <<endl;
			int j = 0;
			cout << "-------------------------" << endl;
			cout << "Das Lexem ist: " << endl;
			while(testItem->lexem[j] != '\0' && j < 5){
					cout << testItem->lexem[j];
					j++;
			}
			cout << "\n-------------------------" << endl;
			testItem = testItem->next;
		}
	}
}

void Symboltable::viewStringTable(){
	StringItem* testStringItem = stringTable;
	while(testStringItem != NULL){
		cout << "Inhalt von StringTabelle " << testStringItem << ": ";
		int j = 0;
		while(j < 5){
			cout << testStringItem->stringMemory[j];
			j++;
		}
		cout << endl;
		testStringItem = testStringItem->next;
	}
}




Symboltable::~Symboltable(){
	for(int i = 0; i < tableSize; i++){
		delete hashTable[i];
	}
}
