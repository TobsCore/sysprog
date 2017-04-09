/*
 * Symboltable.h
 *
 *  Created on: 02.05.2015
 *      Author: holger
 */

#include <iostream>
#include <cstdlib>

#include "Information.h"
#include "../SymbolType/Symboltype.h"
#include "SymbolItem.h"
#include "StringTable/StringTable.h"

using namespace std;

#ifndef Symboltable_H_
#define Symboltable_H_

class SymbolTable {
private:
    /*
     * Integer-Wert zur Array-Größe
     */
    static const int tableSize = 1024;
    /*
     * Die Hashtabelle, die für die
     * verkettete Liste verwendet wird
     */
    SymbolItem *hashTable[tableSize];

    StringTable *stringTable;

    /*
     * Erzeugt eine Adresse, wo der
     * das Element gespeichert wird.
     */
    int hashcode(const char *lexem, int length);

    /*
     * Creates a string, that has only upper characters.
     */
    char *toUpper(const char *s);

public:
    /*
     * Konstruktor der Klasse
     */
    SymbolTable();

    /*
     * Ein Informationselement hinzufügen
     */
    SymbolItem *insert(const char *lexem);

    /*
     * Vorbelegung der Symboltabelle durch Keywords.
     */
    void initSymbols();

    /*
     * Suche nach dem Lexem in der Hashtabelle
     * und gibt Wert aus
     */
    SymbolItem *lookup(const char *lexem);


    /*
     * Checks, whether the given lexem is already in the symboltable.
     */
    bool contains(const char *lexem);

    /*
     *
    void view();
     */

    /*
     * Ausgabe was in der Stringtabelle steht
     */
    //void viewStringTable();

    /*
    * Gibt belegten Speicher von der Hashtabelle
    * frei
    */
    virtual ~SymbolTable();
};


#endif /* Symboltable_H_ */
