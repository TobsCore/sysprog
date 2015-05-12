#include "automat.cpp"
#include <iostream>
using namespace std;

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
    
    checkReturnValue(testAutomat->checkExpression('1'), 0);
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression('3'), 0);
    checkReturnValue(testAutomat->checkExpression('4'), 0);
    checkReturnValue(testAutomat->checkExpression('+'), 1); //Is an integer
    checkReturnValue(testAutomat->checkExpression('5'), 3); //Is a plus sign
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 1); //Is an integer
    checkReturnValue(testAutomat->checkExpression('\0'), 12); //Semicolon


}

void testIdentifierAddition() {
    
    cout << endl << "Test Identifier Addition:" << endl;
    cout << "aaab+a" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression('+'), 2); //Is an identifier
    checkReturnValue(testAutomat->checkExpression('a'), 3); //Is a plus sign
    checkReturnValue(testAutomat->checkExpression('\0'), 2); //Semicolon

}


void testVariableIdentification() {
    
    cout << endl << "Test Identifier Identification:" << endl;
    cout << "int var;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), 0);
    checkReturnValue(testAutomat->checkExpression('n'), 0);
    checkReturnValue(testAutomat->checkExpression('t'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression('\0'), 12); //Semicolon
}


void testIfStatement() {
    
    cout << endl << "Test If Statement:" << endl;
    cout << "if(var1 = var2){\n}" << endl;

    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), 0);
    checkReturnValue(testAutomat->checkExpression('f'), 0);
    checkReturnValue(testAutomat->checkExpression('('), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression('v'), 13); //Open Parentethesis
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression('1'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression('='), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 9);
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression(')'), 2);
    checkReturnValue(testAutomat->checkExpression('{'), 14);
    checkReturnValue(testAutomat->checkExpression('\n'), 15);
    checkReturnValue(testAutomat->checkExpression('}'), 0);
    checkReturnValue(testAutomat->checkExpression('\0'), 16);
}


void testAssignment() {
    
    cout << endl << "Test Assign Statement:" << endl;
    cout << "int var := 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), 0);
    checkReturnValue(testAutomat->checkExpression('n'), 0);
    checkReturnValue(testAutomat->checkExpression('t'), 0); //Identifier
    checkReturnValue(testAutomat->checkExpression(' '), 2); //Open Parentethesis
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression(':'), 0);
    checkReturnValue(testAutomat->checkExpression('='), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 19);
    checkReturnValue(testAutomat->checkExpression('3'), 0);
    checkReturnValue(testAutomat->checkExpression('5'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 1);
    checkReturnValue(testAutomat->checkExpression('\0'), 12);
}


void testSpecial() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "var <:> 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2); //Identifier
    checkReturnValue(testAutomat->checkExpression('<'), 0);
    checkReturnValue(testAutomat->checkExpression(':'), 0);
    checkReturnValue(testAutomat->checkExpression('>'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 20);
    checkReturnValue(testAutomat->checkExpression('3'), 0);
    checkReturnValue(testAutomat->checkExpression('5'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 1);
    checkReturnValue(testAutomat->checkExpression('\0'), 12);
}


void testArray() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "var1[56] = var2 <:> 35;" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression('['), 2);
    checkReturnValue(testAutomat->checkExpression('5'), 17);
    checkReturnValue(testAutomat->checkExpression('6'), 0);
    checkReturnValue(testAutomat->checkExpression(']'), 1); //Identifier
    checkReturnValue(testAutomat->checkExpression(' '), 18);
    checkReturnValue(testAutomat->checkExpression('v'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('r'), 0);
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('<'), 0);
    checkReturnValue(testAutomat->checkExpression(':'), 0);
    checkReturnValue(testAutomat->checkExpression('>'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 20);
    checkReturnValue(testAutomat->checkExpression('3'), 0);
    checkReturnValue(testAutomat->checkExpression('5'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 1);
    checkReturnValue(testAutomat->checkExpression('\0'), 12);
}


void testBoolean() {
    
    cout << endl << "Test Special Statement:" << endl;
    cout << "if(a = b & !b = a & b < a & b > a);" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('i'), 0);
    checkReturnValue(testAutomat->checkExpression('f'), 0);
    checkReturnValue(testAutomat->checkExpression('('), 2);
    checkReturnValue(testAutomat->checkExpression('a'), 13);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('='), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 9);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('&'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 11);
    checkReturnValue(testAutomat->checkExpression('!'), 0);
    checkReturnValue(testAutomat->checkExpression('b'), 10);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('='), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 9);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('&'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 11);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('<'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 7);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('&'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 11);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 2);
    checkReturnValue(testAutomat->checkExpression('>'), 0);
    checkReturnValue(testAutomat->checkExpression(' '), 8);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression(')'), 2);
    checkReturnValue(testAutomat->checkExpression(';'), 14);
    checkReturnValue(testAutomat->checkExpression('\0'), 12);
}



void checkReturnValue(int returnValue, int expectedValue) {
    if(returnValue == expectedValue) {
        cout << "OK";
    } else {
        cout << "########" << "Error";
    }
    
    cout << "- Got: " << returnValue << " | Expected: " << expectedValue << endl;
}
