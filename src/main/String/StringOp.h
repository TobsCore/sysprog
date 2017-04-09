//
// Created by Tobias Kerst on 09.04.17.
//

#ifndef SYSPROG_STRINGOP_H
#define SYSPROG_STRINGOP_H


class StringOp {
public:
    /*
     * Gibt die Länge eines Wortes zurück
     */
    static int length(const char *lexem);

    /*
     * Vergleiche Lexem mit gespeicherten
     * Wort im Element
     */
    static bool compare(const char *lexem1, const char *lexem2);

};


#endif //SYSPROG_STRINGOP_H
