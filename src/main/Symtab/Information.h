/*
 * Information.h
 *
 *  Created on: 03.05.2015
 *      Author: holger
 */

#include <iostream>
#include <cstdlib>

#include "../SymbolType/symboltype.h"
#include "Keyword.h"

using namespace std;

#ifndef INFORMATION_H_
#define INFORMATION_H_

class Information {
	private:

		Signtype type;
		char* name;
		Keyword keyword;

	public:
		/*
		* Default-Konstruktor von der Klasse
		*/
		Information();
		/*
		 * Konstruktor von der Klasse
		 */
		Information(Signtype type, char* name);
		/*
		 * Gibt Name von Informationscontainer aus
		 */
		char* getName();
		/*
		 * Ändert Name von Informationscontainer
		 */
		void setName(char* name2);
		/*
		 * Gibt Typ von Informationscontainer aus
		 */
		Signtype getType();
		/*
		 * Ändert Typ von Informationscontainer
		 */
		void setType(Signtype type2);
		/*
		 * Gibt Keyword von Informationscontainer aus
		 */
		Keyword getKeyword();
		/*
		 * Ändert Keyword von Informationscontainer
		 */
		void setKeyword(Keyword keyword2);
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
		 * Ausgabe von Informationscontainer
		 */
		void viewInformation();
		/*
		 * Aktueller Informationscontainer erhält
		 * alle Werte von anderen Infocontainer

		Information& operator=(Information& infoGleich);

		* Aktueller Informationscontainer wird mit dem
		* anderen verglichen

		bool operator==(Information& infoVergleich);*/



		/*
		* Gibt belegten Speicher von der Hashtabelle
		* frei
		*/
		virtual ~Information();
};



#endif /* INFORMATION_H_ */
