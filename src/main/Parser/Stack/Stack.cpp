/*
 * Stack.cpp
 *
 *  Created on: 13.06.2017
 *      Author: holger
 */


#include "Stack.h"

Stack::Stack(){
	stackP = 0;
	codeP = 0;
};

Stack::~Stack(){ };

void Stack::addStack(){
	codeP++;
	*(stackP-1) = *(stackP-1) + *stackP;
	stackP--;
};
void Stack::mulStack(){
	codeP++;
	*(stackP-1) = *(stackP-1) * *stackP;
	stackP--;
};
void Stack::subStack(){
	codeP++;
	*(stackP-1) = *(stackP-1) - *stackP;
	stackP--;
};
void Stack::divStack(){
	codeP++;
	*(stackP-1) = *(stackP-1) / *stackP;
	stackP--;
};


void Stack::lesStack(){
	codeP++;
	if (*(stackP-1) < *stackP){
		*(stackP-1) = 1;
	}
	else
	{
		*(stackP-1) = 0;
	}
	stackP--;
};
void Stack::equStack(){
	codeP++;
	if (*(stackP-1) == *stackP)
	{
		*(stackP-1) = 1;
	}
	else
	{
		*(stackP-1) = 0;
	}
	stackP--;
};


void Stack::andStack(){
	codeP++;
	if (*(stackP-1) != 0 && *stackP != 0)
	{
		*(stackP-1) = 1;
	}
	else {
		*(stackP-1) = 0;
	}
	stackP--;
};
void Stack::notStack(){
	codeP++;
	if (*(stackP) == 0 )
	{
		*stackP = 1;
	}
	else
	{
		*stackP = 0;
	}
};


/*void Stack::laStack(variable){
	codeP += 2; stackP++;
	*stackP =addr(varianble);
};*/
void Stack::lcStack(int c){
	codeP += 2;
	stackP++;
	*stackP = c;
};
void Stack::lvStack(){
	codeP++;
	*stackP = **stackP;
};
void Stack::strStack(){
	codeP++;
	**stackP = *(stackP-1);
	stackP -=2;
};

void Stack::priStack(){
	codeP ++;
//	cout << *stackP << endl;
	stackP--;
};
void Stack::reaStack(){
	codeP ++; stackP++;
//	*stackP = read();
};

/* void Stack::jmpStack(label){
	codeP = *label
	// springt an die mit
	// *label markierte Codezeile
};
void Stack::jinStack(label){
	if(*stackP == 0)
	{
		codeP = *label;
	}
	else
	{
		codeP +=2;
	}
	stackP--;
}

void Stack::dsStack(identifier, int size){
	codeP+=3;
	addr(identifier) = addrP;
	addrP += size;
};
void Stack::nopStack(){
	codeP++;
};
void Stack::stpStack(){
	exit();
};*/


