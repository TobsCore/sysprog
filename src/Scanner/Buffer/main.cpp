/*
 * main.cpp
 *
 *  Created on: 07.05.2015
 *      Author: patrick
 */
#include <iostream>
#include "Buffer.h"
using namespace std;

int main() {
	char* filePath = "./test.txt";

	Buffer* joo = new Buffer(filePath);
	for (int i = 0; i< 1600; i++)
	{
	char c = joo->getChar();
	cout << "mein char: " << i << ": " << c << endl;
	}
	return 0;
}



