#include "automat.cpp"
#include <iostream>
using namespace std;

void simpleTest();
void testIdentifierAddition();
void checkReturnValue(int returnValue, int expectedValue);


int main () {
    
    simpleTest();
    testIdentifierAddition();
	return 0;
}

void simpleTest() {
    
    cout << "Test Integer Addition Addition:" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('1'), 0);
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression('3'), 0);
    checkReturnValue(testAutomat->checkExpression('4'), 0);
    checkReturnValue(testAutomat->checkExpression('+'), 1); //Is an integer
    checkReturnValue(testAutomat->checkExpression('5'), 3); //Is a plus sign
    checkReturnValue(testAutomat->checkExpression('2'), 0);
    checkReturnValue(testAutomat->checkExpression(';'), 1); //Is an integer

}

void testIdentifierAddition() {
    
    cout << endl << "Test Identifier Addition:" << endl;
    Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression('+'), 2); //Is an identifier
    checkReturnValue(testAutomat->checkExpression('a'), 3); //Is a plus sign
}



void checkReturnValue(int returnValue, int expectedValue) {
    if(returnValue == expectedValue) {
        cout << "OK";
    } else {
        cout << "Error";
    }
    
    cout << "- Got: " << returnValue << " | Expected: " << expectedValue << endl;
}
