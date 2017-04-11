//
// Created by Holger on 09.04.17.
//


#include <iostream>
#include "StringTable.h"
#include "../../String/StringOp.h"

using namespace std;

StringTable::StringTable() {
    this->item = new StringItem;
    this->ptrStringMemory = item->stringMemory;
    this->item->stringMemory = (char *) calloc(stringMemorySize, sizeof(char));
    this->item->next = NULL;
    this->counterStringMemory = 0;
}

char *StringTable::insertString(const char *lexem) {
    // Erstelle ein Pointer auf Stringtabelle und gehe
    // zum letzten Element
    StringItem *ptrStringItem = item;
    while (ptrStringItem->next != NULL) {
        ptrStringItem = ptrStringItem->next;
    }

    // Findet vor dem einfügen heraus, ob
    // ein neues Element angelegt werden muss
    int lexemLength = StringOp::length(lexem);

    // Abfangen von Wörter die größer als
    // der Stringmemory ist
    if (lexemLength > stringMemorySize) {
        return NULL;
    }
        // ... ansonsten wenn Länge des Lexem größer ist als die
        // StringMemory, dann eine neue StringMemory erstellen
    else if ((lexemLength + counterStringMemory) > stringMemorySize) {

        // Speicher für neues Element bereitstellen
        // und ausgeben wenn es keinen mehr gibt
        StringItem *newStringItem = new StringItem;

        // Neues Element bekommt Werte und wird
        // an Stringtabelle verknüpft
        newStringItem->stringMemory = (char *) calloc(stringMemorySize, sizeof(char));
        if (newStringItem->stringMemory == NULL) {
            // Kein Speicher für neues Element vorhanden
            return NULL;
        }
        newStringItem->next = NULL;
        ptrStringItem->next = newStringItem;

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
    while (lexem[i] != '\0') {
        ptrStringMemory[i] = lexem[i];
        i++;
    }
    ptrStringMemory[i] = '\0';
    counterStringMemory += i + 1;

    // Rückgabe der Position des neuen Wortes
    return ptrStringMemory;
}


StringTable::~StringTable() {
    freeRecursive(item);
    delete item;
}

void StringTable::freeRecursive(StringItem *item) {
    if (item->next != NULL) {
        freeRecursive(item->next);
        delete (item->next);
    }
    free(item->stringMemory);
}
