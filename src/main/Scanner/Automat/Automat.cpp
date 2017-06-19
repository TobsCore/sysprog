// Der Automat merkt sich, in welchem Zustand er ist.
// Gibt Integer Werte zurück, die jeweils für die entsprechenden Typen des Tokens stehen.


#include "Automat.h"
#include "State.h"

int Automat::findColumn(char currentChar) {
    if ((int) currentChar > 47 && (int) currentChar < 58) {
        //digit
        return 0;

    } else if (currentChar == 'i') {
        return 19;
    } else if (currentChar == 'f') {
        return 20;
    } else if (currentChar == 'w') {
        return 21;
    } else if (currentChar == 'h') {
        return 22;
    } else if (currentChar == 'l') {
        return 23;
    } else if (currentChar == 'e') {
        return 24;
    } else if (currentChar == 's') {
        return 25;
    } else if (currentChar == 'r') {
        return 26;
    } else if (currentChar == 'a') {
        return 27;
    } else if (currentChar == 'd') {
        return 28;
    } else if (currentChar == 't') {
        return 29;
    } else if (currentChar == 'n') {
        return 30;
    } else if (currentChar == 'I') {
        return 31;
    } else if (currentChar == 'F') {
        return 32;
    } else if (currentChar == 'W') {
        return 33;
    } else if (currentChar == 'H') {
        return 34;
    } else if (currentChar == 'L') {
        return 35;
    } else if (currentChar == 'E') {
        return 36;
    } else if (currentChar == 'S') {
        return 37;
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
            case '$':
                return 38;
            case '#':
                return 38;
            case ',':
                return 38;
            case '.':
                return 38;
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
