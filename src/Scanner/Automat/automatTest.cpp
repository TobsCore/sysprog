#include "automat.cpp"
#include <iostream>
using namespace std;

int main () {

	Automat* testAutomat = new Automat();

	cout << testAutomat->checkExpression('a') << endl;
	cout << testAutomat->checkExpression('a') << endl;
	cout << testAutomat->checkExpression('a') << endl;
	cout << testAutomat->checkExpression('1') << endl;
	cout << testAutomat->checkExpression('+') << endl;
	cout << testAutomat->checkExpression('4') << endl;
	cout << testAutomat->checkExpression('a') << endl;
//	cout << "hello" << endl;
	return 0;
}
