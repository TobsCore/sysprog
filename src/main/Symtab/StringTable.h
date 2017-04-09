//
// Created by Tobias Kerst on 09.04.17.
//

#ifndef SYSPROG_STRINGTABLE_H
#define SYSPROG_STRINGTABLE_H


class StringTable {
private:

    /*
     * Size of the string buffer.
     */
    static const int stringMemorySize = 10000;
    /*
     * Pointer für die Stringspeicher
     */
    char *ptrStringMemory;
    /*
     * Struktur von einem Element
     * in der Stringtabelle
     */
    struct StringItem {
        char stringMemory[stringMemorySize];
        StringItem *next;
    };
    /*
     * Aufrufbares Element der Stringtabelle
     */
    StringItem *item;
    /*
     * Counter, um zu sehen wieviel
     * im Stringspeicher schon belegt ist
     */
    int counterStringMemory;

public:
    StringTable();

    /*
     * Wert in Stringtabelle einfügen
     */
    char *insertString(const char *lexem);
};


#endif //SYSPROG_STRINGTABLE_H
