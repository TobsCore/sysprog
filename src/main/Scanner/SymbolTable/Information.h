/*
 * Information.h
 *
 *  Created on: 03.05.2015
 *      Author: holger
 */

#include <iostream>
#include <cstdlib>

#include "../SymbolType/Symboltype.h"
#include "Keyword.h"

using namespace std;

#ifndef INFORMATION_H_
#define INFORMATION_H_

class Information {
private:

    SymbolType type;
    const char *name;
    Keyword keyword;

public:
    /*
    * Default-Konstruktor von der Klasse
    */
    Information();

    /*
     * Konstruktor von der Klasse
     */
    Information(const char *name);

    /*
     * Ändert Name von Informationscontainer
     */
    void setName(const char *name2);

    /*
     * überprüft ob Lexem ein Keyword ist oder nicht.
     * Und gibt das den entsprechende Keyword zurück
     */
    Keyword isKeyword();

    /*
     * Gibt die Länge von dem Namen aus
     */
    int nameLength();

    /*
    * Gibt belegten Speicher von der Hashtabelle
    * frei
    */
    virtual ~Information();
};


#endif /* INFORMATION_H_ */
