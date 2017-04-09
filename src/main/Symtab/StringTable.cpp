//
// Created by Tobias Kerst on 09.04.17.
//


#include <iostream>
#include "StringTable.h"
#include "../String/StringOp.h"


StringTable::StringTable() {

    this->item = new StringItem;
    this->ptrStringMemory = item->stringMemory;
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
    int length = StringOp::length(lexem);
    if ((length + counterStringMemory) >= stringMemorySize) {

        // Speicher für neues Element bereitstellen
        // und ausgeben wenn es keinen mehr gibt
        StringItem *newStringItem = (StringItem *) malloc(sizeof(StringItem *));
        if (newStringItem == NULL) {
            //cout << "Kein Speicher für neues Element vorhanden" << endl;
            return NULL;
        }
        // Neues Element bekommt Werte und wird
        // an Stringtabelle hinzugefügt
        newStringItem->next = NULL;
        item->next = newStringItem;

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
        counterStringMemory++;
        i++;
    }
    ptrStringMemory[i] = '\0';
    counterStringMemory++;

    // Rückgabe von der Position des neuen Wortes
    return ptrStringMemory;
}