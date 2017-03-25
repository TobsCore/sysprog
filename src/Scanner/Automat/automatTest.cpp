#ifndef AUTOMAT
#define AUTOMAT
#include "automat.h"
#endif

#ifndef SYMBOLTYPE
#define SYMBOLTYPE
#include "../../SymbolType/symboltype.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif
using namespace std;
using namespace sign;

void simpleTest();
void testIdentifierAddition();
void testVariableIdentification();
void testIfStatement();
void testAssignment();
void testSpecial();
void testArray();
void testBoolean();
void checkReturnValue(int returnValue, int expectedValue);


int main () {
    
    simpleTest();
    testIdentifierAddition();
    testVariableIdentification();
    testIfStatement();
    testAssignment();
    testSpecial();
    testArray();
    testBoolean();
	return 0;
}

void simpleTest() {
    
    cout << "Test Integer Addition Addition:" << endl;
    cout << "1234+52;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('1'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('2'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('3'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('4'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('+'), INTEGER); //Is an integer
    checkReturnValue(testAutomat->checkExpression('5'), PLUS); //Is a plus sign
    checkReturnValue(testAutomat->checkExpression('2'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(';'), INTEGER); //Is an integer
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON); //Semicolon


}

void testIdentifierAddition() {
    
    cout << endl << "Test Identifier Addition:" << endl;
    cout << "aaab+a" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('b'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('+'), IDENTIFIER); //Is an identifier
    checkReturnValue(testAutomat->checkExpression('a'), PLUS); //Is a plus sign
    checkReturnValue(testAutomat->checkExpression('\0'), IDENTIFIER); //Semicolon

}


void testVariableIdentification() {
    
    cout << endl << "Test Identifier Identification:" << endl;
    cout << "int var;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('n'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('t'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(';'), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON); //Semicolon
}


void testIfStatement() {
    
    cout << endl << "Test If Statement:" << endl;
    cout << "if(var1 = var2){\n}" << endl;

    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('f'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('('), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression('v'), PARANTHESES_LEFT); //Open Parentethesis
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('1'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression('='), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), EQUALS);
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('2'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(')'), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('{'), PARANTHESES_RIGHT);
    checkReturnValue(testAutomat->checkExpression('\n'), BRACES_LEFT);
    checkReturnValue(testAutomat->checkExpression('}'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('\0'), BRACES_RIGHT);
}


void testAssignment() {
    
    cout << endl << "Test Assign Statement:" << endl;
    cout << "int var := 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('n'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('t'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression(':'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('='), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), ASSIGN);
    checkReturnValue(testAutomat->checkExpression('3'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('5'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(';'), INTEGER);
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON);
}


void testSpecial() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "var <:> 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER); //Identifier
    checkReturnValue(testAutomat->checkExpression('<'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(':'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('>'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), SPECIAL);
    checkReturnValue(testAutomat->checkExpression('3'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('5'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(';'), INTEGER);
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON);
}


void testArray() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "var1[56] = var2 <:> 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('['), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('5'), BRACKET_LEFT);
    checkReturnValue(testAutomat->checkExpression('6'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(']'), INTEGER); //Identifier
    checkReturnValue(testAutomat->checkExpression(' '), BRACKET_RIGHT);
    checkReturnValue(testAutomat->checkExpression('v'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('r'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('2'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('<'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(':'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('>'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), SPECIAL);
    checkReturnValue(testAutomat->checkExpression('3'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('5'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(';'), INTEGER);
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON);
}


void testBoolean() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "if(a = b & !b = a & b < a & b > a);" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('f'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('('), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('a'), PARANTHESES_LEFT);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('='), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), EQUALS);
    checkReturnValue(testAutomat->checkExpression('b'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('&'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), AND);
    checkReturnValue(testAutomat->checkExpression('!'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression('b'), EXCLAMATION);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('='), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), EQUALS);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('&'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), AND);
    checkReturnValue(testAutomat->checkExpression('b'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('<'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), LESS);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('&'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), AND);
    checkReturnValue(testAutomat->checkExpression('b'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression('>'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(' '), GREATER);
    checkReturnValue(testAutomat->checkExpression('a'), NEXTCHAR);
    checkReturnValue(testAutomat->checkExpression(')'), IDENTIFIER);
    checkReturnValue(testAutomat->checkExpression(';'), PARANTHESES_RIGHT);
    checkReturnValue(testAutomat->checkExpression('\0'), SEMICOLON);
}



void checkReturnValue(int returnValue, int expectedValue) {
    if(returnValue == expectedValue) {
        cout << "OK";
    } else {
        cout << "########" << "Error";
    }
    
    cout << "- Got: " << returnValue << " | Expected: " << expectedValue << endl;
}
