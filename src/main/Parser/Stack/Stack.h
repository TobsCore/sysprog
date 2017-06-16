/*
 * Stack
 *
 *  Created on: 13.06.2017
 *      Author: holger
 */

#ifndef MAIN_PARSER_STACK_STACK_H_
#define MAIN_PARSER_STACK_STACK_H_

class Stack {

public:
	Stack();
	~Stack();

	int *stackP;
	int *codeP;

	// Arithmetik-Befehle
	void addStack();
	void mulStack();
	void subStack();
	void divStack();

	// Vergleiche ohne Argument
	void lesStack();
	void equStack();

	// Logische	Operationen	ohne Argument
	void andStack();
	void notStack();

	// Speichern und laden
//	void laStack(variable);
	void lcStack(int c);
	void lvStack();
	void strStack();

	// Einlesen	und	Drucken	ohne Argument
	void priStack();
	void reaStack();

	// Sprünge mit Argumenten
//	void jmpStack(label);
//	void jinStack(label)

	// Speichern und reservieren
//	void dsStack(identifier, int size);

	// Andere Operationen
	void nopStack();
	void stpStack();
};

#endif /* MAIN_PARSER_STACK_STACK_H_ */
