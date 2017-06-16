/*
 * Grammar.h
 *
 *  Created on: 14.06.2017
 *      Author: holger
 */

#ifndef SYSPROG_GRAMMAR_H_
#define SYSPROG_GRAMMAR_H_

class Grammar {
private:
	Node* node;
public:
	Grammar();
	virtual ~Grammar();

	void typeCheck(Node* node);

	Node* decls();
	Node* decl();

	Node* statements();
	Node* statement();

	Node* nextDecl();
	Node* nextStatement();
	Node* array();
	Node* exp();
	Node* exp2();
	Node* op();
	Node* index();
	Node* statement_if();
	Node* statement_else();
};

#endif /* MAIN_PARSER_PARSER_GRAMMAR_H_ */
