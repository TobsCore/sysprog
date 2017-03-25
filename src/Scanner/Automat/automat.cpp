// Der Automat merkt sich, in welchem Zustand er ist.
// Gibt Integer Werte zurück, die jeweils für die entsprechenden Typen des Tokens stehen.

// Aus schlüsselwörtern wie "if" und "while" werden Identifier gemacht

/** Es wird ein int zurückgegeben, dass durch ein enum eine schöne Beschreibung bekommt
 * -1 > baue ein FehlerToken
 * 0 > noch ein char, bitte!
 * 1 > baue ein IntegerToken
 * 2 > baue ein IdentifierToken
 * 3 > baue ein PlusToken
 * 4 > baue ein MinusToken
 * etc.
 */

#ifndef AUTOMAT
#define AUTOMAT
#include "automat.h"
#endif

//#ifndef SYMTYPE
//#define SYMTYPE
//#include <symboltype.h>
//#endif
//using namespace sign;

int Automat::findColumn(char currentChar) {
	if ((int) currentChar > 47 && (int) currentChar < 58) {
		//digit
		return 0;
	} else if (((int) currentChar > 64 && (int) currentChar < 91) // uppercase Letter
	|| ((int) currentChar > 96 && (int) currentChar < 123)) // lowercase Letter
			{
		// Letter
		return 1;
	} else {
		switch (currentChar) {
		case '+':
			return 2;
		case '-':
			return 3;
		case ':':
			return 4;
		case '*':
			return 5;
		case '<':
			return 6;
		case '>':
			return 7;
		case '=':
			return 8;
		case '!':
			return 9;
		case '&':
			return 10;
		case ';':
			return 11;
		case '(':
			return 12;
		case ')':
			return 13;
		case '{':
			return 14;
		case '}':
			return 15;
		case '[':
			return 16;
		case ']':
			return 17;
		default:
			return 18;
		}
	}
}

Automat::Automat() {
	this->currentState = 0;
	this->newState = 0;
	this->column = 0;



}

int Automat::checkExpression(char currentChar) {
	currentState = newState;
	column = findColumn(currentChar);
	stateElement state = stateMatrix[currentState][column];
	newState = state.nextState;

	return state.returnValue;
}
