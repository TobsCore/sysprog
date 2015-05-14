#ifndef IO
#define IO
#include <iostream>
#endif

#ifndef BUFFER
#define BUFFER
#include "Buffer.h"
#endif

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



