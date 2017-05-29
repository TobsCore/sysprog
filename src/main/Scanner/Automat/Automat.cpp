// Der Automat merkt sich, in welchem Zustand er ist.
// Gibt Integer Werte zurück, die jeweils für die entsprechenden Typen des Tokens stehen.


#ifndef AUTOMAT
#define AUTOMAT

#include "Automat.h"

#endif

#ifndef SYSPROG_STATE_H
#define SYSPROG_STATE_H

#include "State.h"

#endif

int Automat::findColumn(char currentChar) {
    if ((int) currentChar > 47 && (int) currentChar < 58) {
        //digit
        return 0;

    } else if ((currentChar == 'i' || currentChar == 'I')) {
        return 19;
    } else if ((currentChar == 'f' || currentChar == 'F')) {
        return 20;
    } else if ((currentChar == 'w' || currentChar == 'W')) {
        return 21;
    } else if ((currentChar == 'h' || currentChar == 'H')) {
        return 22;
    } else if ((currentChar == 'l' || currentChar == 'L')) {
        return 23;
    } else if ((currentChar == 'e' || currentChar == 'E')) {
        return 24;
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

SymbolType Automat::checkExpression(char currentChar) {
    currentState = newState;
    column = findColumn(currentChar);
    StateElement state = stateMatrix[currentState][column];
    newState = state.nextState;

    return state.returnValue;
}
