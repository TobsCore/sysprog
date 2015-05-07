#include "automat.cpp"
#include <iostream>
using namespace std;

void checkReturnValue(int returnValue, int expectedValue);


int main () {

	Automat* testAutomat = new Automat();
    
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('a'), 0);
    checkReturnValue(testAutomat->checkExpression('b'), 0);
    checkReturnValue(testAutomat->checkExpression('+'), 2); //Is an identifier
    checkReturnValue(testAutomat->checkExpression('a'), 3); //Is a plus sign
	return 0;
}

void checkReturnValue(int returnValue, int expectedValue) {
    if(returnValue == expectedValue) {
        cout << "OK";
    } else {
        cout << "Error";
    }
    
    cout << "- Got: " << returnValue << " | Expected: " << expectedValue << endl;
}
