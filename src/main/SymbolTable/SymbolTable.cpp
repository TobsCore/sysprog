/*
 * Symboltable.cpp
 *
 *  Created on: 02.05.2015
 *      Author: holger
 */


#include "SymbolTable.h"
#include "Keywords.h"
#include "../String/StringOp.h"

using namespace std;

SymbolTable::SymbolTable() {
    for (int i = 0; i < tableSize; i++) {
        this->hashTable[i] = NULL;
    }
    this->stringTable = new StringTable();
}


int SymbolTable::hashcode(const char *lexem, int length) {
    int hashCode = (16 * lexem[0] + 8 * lexem[length - 1] + length);
    return hashCode % tableSize;
}


SymbolItem *SymbolTable::insert(const char *lexem) {
    // Erstelle einen Pointer für das Element
    SymbolItem *ptrItem;

    // Berechne die Hashadresse, an der das neue Element
    // gespeichert wird
    int lexemLength = StringOp::length(lexem);
    int hashAdress = hashcode(lexem, lexemLength);

    // Pointer zeigt auf die errechnete Hashadresse
    // in der Hashtabelle
    ptrItem = hashTable[hashAdress];

    // Suche freien Platz auf der errechnete Hashadresse
    // und schaue ob das Element schon gibt
    while (ptrItem != NULL) {
        if (StringOp::compare(ptrItem->lexem, lexem)) {
            //cout << "Das Element gibt es schon!" << endl;
            return ptrItem;
        }
        ptrItem = ptrItem->next;
    }

    // Speicher für neues Element bereitstellen und ausgeben
    // wenn es keinen mehr gibt
    ptrItem = (SymbolItem *) malloc(sizeof(SymbolItem) + sizeof(Information));

    if (ptrItem == NULL) {
        // cout << "Kein Speicher für neues Element vorhanden" << endl;
        return NULL;
    }


    // Fügt ale Werte in das neues Element ein
    ptrItem->infoContainer.setName(lexem);
    ptrItem->lexem = stringTable->insertString(lexem);

    // Fügt neues Element in die Hashtabelle ein
    ptrItem->next = hashTable[hashAdress];
    hashTable[hashAdress] = ptrItem;
    //delete ptrItem;

    cout << "insert: Lexem = " << hashTable[hashAdress]->lexem << " auf der Hashadresse " << hashAdress << endl;
    return ptrItem;
}

bool SymbolTable::contains(const char *lexem) {
    SymbolItem *item = lookup(lexem);
    return item != NULL;
}

SymbolItem *SymbolTable::lookup(const char *lexem) {
    // Erstelle einen Pointer für das Element
    SymbolItem *ptrItem;

    // Berechne die Hashadresse, wo das Element
    // gespeichert wurde
    int lexemLength = StringOp::length(lexem);
    int hashAdress = hashcode(lexem, lexemLength);

    // Pointer zeigt auf die errechnete Hashadresse
    // in der Hashtabelle
    ptrItem = hashTable[hashAdress];

    // Suche Element auf der errechnete Hashadresse
    while (ptrItem != NULL) {
        if (StringOp::compare(ptrItem->lexem, lexem)) {
            return ptrItem;
        }
        ptrItem = ptrItem->next;
    }
    return NULL;
}

void SymbolTable::initSymbols() {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        insert(KEYWORDS[i]);
        insert(StringOp::toUpper(KEYWORDS[i]));
    }
}

SymbolTable::~SymbolTable() {
    for (int i = 0; i < tableSize; i++) {
        delete hashTable[i];
    }
}
