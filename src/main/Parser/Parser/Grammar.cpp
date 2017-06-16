/*
 * Grammar.cpp
 *
 *  Created on: 14.06.2017
 *      Author: holger
 */

#include "Grammar.h"
#include "Node.h"
#include "Rule.h"

Grammar::Grammar() {
	node = new Node();
}

Grammar::~Grammar() {
	delete node;
}

/*
 * Mit dem typeCheck() wird überprüft, ob im Parsertree
 * auch der richtige Type gespeichert wurde. Dafür wird
 * die rekursive Methode benutzt. Je nach RuleTyp, dass
 * im Node gespeichert wurde. Werden die Kindblätter daraufhin
 * überprüft, ob sie auch die entsprechenden RuleTypen
 * haben. Zur Überprüfung der Kindblätter wird typeCheck
 * wieder aufgerufen. Gibt es da ein Fehler, dann wird dem
 * Node_Type in ERROR_TYPE überschrieben.
 *
 */
void Grammar::typeCheck(Node* node){
	this->node = node;
	switch(node->ruleType()){

		// Startsymbol
		case PROG:
			this->typeCheck(this->decl());
			this->typeCheck(this->statements());
			node->setType(NO_TYPE);
			break;

		case DECLS:
			this->typeCheck(this->decl());
			this->typeCheck(this->nextDecl());
			break;

		case DECLS_EMPTY:
			break;

		case DECL:
			if(node->getType() != NO_TYPE) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else {
				if(this->array() != nullptr) {
					this->typeCheck(this->array());
					node->setType(INT_ARRAY_TYPE);
				} else {
					node->setType(INT_TYPE);
				}
			}
			break;

		case ARRAY:
			if(*(node->integerValue) > 0) {
				node->setType(INT_ARRAY_TYPE);
			} else {
				node->setType(ERROR_TYPE);
				exit(1);
			}
			break;

		case ARRAY_EMPTY:
			break;

		case STATEMENTS:
			this->typeCheck(this->statement());
			this->typeCheck(this->nextStatement());
			break;

		case STATEMENTS_EMPTY:
			break;

		case STATEMENT_IDENTIFIER:
			this->typeCheck(this->exp());
			this->typeCheck(this->index());
			if(node->getType() == NO_TYPE) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else {
					if(!(this->exp()->getType() == INT_TYPE
					&& ((node->getType() == INT_TYPE
					&& this->index()->getType() == NO_TYPE)
					|| (node->getType() == INT_ARRAY_TYPE
					&& this->index()->getType() == INT_ARRAY_TYPE)))) {

						node->setType(ERROR_TYPE);
						exit(1);
					}
			}
			break;

		case STATEMENT_WRITE:
			this->typeCheck(this->exp());
			break;

		case STATEMENT_READ:
			std::cout << "read" << std::endl;
			this->typeCheck(this->index());
			if(node->getType() == NO_TYPE) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else {
				if(!((node->getType() == INT_TYPE
				&& this->index()->getType() == NO_TYPE)
				|| (node->getType() == INT_ARRAY_TYPE
				&& this->index()->getType() == INT_ARRAY_TYPE))) {
					node->setType(ERROR_TYPE);
					exit(1);
				}
			}
			break;

		case STATEMENT_BLOCK:
			this->typeCheck(this->statements());
			break;

		case STATEMENT_IF:
			this->typeCheck(this->exp());
			this->typeCheck(this->statement_if());
			this->typeCheck(this->statement_else());
			break;

		case STATEMENT_WHILE:
			this->typeCheck(this->exp());
			this->typeCheck(this->statement());
			break;

		case EXP:
			this->typeCheck(this->exp2());
			this->typeCheck(this->op());
			if(this->op() == NO_TYPE) {
				node->setType(this->exp2()->getType());
			} else if(this->op()->getType() != this->exp2()->getType()) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else {
				node->setType(this->exp2()->getType());
			}
			break;

		case EXP2:
			this->typeCheck(this->exp());
			node->setType(this->exp()->getType());
			break;

		case EXP2_INBRACKETS:
			this->typeCheck(this->exp());
			node->setType(this->exp()->getType());
			break;

		case EXP2_IDENTIFIER:
			this->typeCheck(this->index());
			if(node->getType() == NO_TYPE) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else if(node->getType() == INT_TYPE
			&& this->index()->getType() == NO_TYPE) {
				node->setType(node->getType());
			} else if(node->getType() == INT_ARRAY_TYPE
			&& this->index()->getType() == INT_ARRAY_TYPE) {
				node->setType(INT_TYPE);
			} else {
				node->setType(ERROR_TYPE);
				exit(1);
			}
			break;

		case EXP2_INTEGER:
			node->setType(INT_TYPE);
			break;

		case EXP2_MINUS:
			this->typeCheck(this->exp2());
			node->setType(this->exp2()->getType());
			break;


		case EXP2_NEGATION:
			this->typeCheck(this->exp2());
			if(this->exp2()->getType() != INT_TYPE) {
				node->setType(ERROR_TYPE);
				exit(1);
			} else {
				node->setType(INT_TYPE);
			}
			break;

		case INDEX:
			this->typeCheck(this->exp());
			node->setType(INT_ARRAY_TYPE);
			break;

		case INDEX_EMPTY:
			break;

		case OP_EXP :
			this->typeCheck(this->op());
			this->typeCheck(this->exp());
			node->setType(this->exp()->getType());
			break;

		case OP_EXP_EMPTY :
			break;

		case OP_PLUS:
			node->setType(INT_TYPE);
			break;

		case OP_MINUS:
			node->setType(INT_TYPE);
			break;

		case OP_MUL:
			node->setType(INT_TYPE);
			break;

		case OP_DIV:
			node->setType(INT_TYPE);
			break;

		case OP_LESS:
			node->setType(INT_TYPE);
			break;

		case OP_GREATER:
			node->setType(INT_TYPE);
			break;
		case OP_EQUAL:
			node->setType(INT_TYPE);
			break;

		case OP_SPECIAL:
			node->setType(INT_TYPE);
			break;

		case OP_AND:
			node->setType(INT_TYPE);
			break;

		case RULE_NOT_SET:
			node->setType(ERROR_TYPE);
			exit(1);
			break;

		default:
			break;
	}

}

Node* Grammar::decls(){
	if(node->getRuleType() == PROG) {
	    return node->getChild(1);
	} else {
		node->setRuleType(RULE_NOT_SET);
		return nullptr;
	}
}

Node* Grammar::decl(){
	if(node->ruleType == DECLS
	|| node->ruleType == DECLS_EMPTY){
		return node->getChild(1);
	} else {
		node->setRuleType(RULE_NOT_SET);
		return nullptr;
	}
}

Node* Grammar::nextDecl() {
	if(node->ruleType == DECLS) {
		return node->getChild(2);
	}
}

Node* Grammar::statements() {
  if(node->ruleType == PROG){
	  return node->getChild(2);
  } else if(node->ruleType == STATEMENT_BLOCK) {
	  return node->getChild(1);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node * Grammar::statement() {
  if(node->ruleType == STATEMENTS
  || node->ruleType == STATEMENTS_EMPTY ) {
	  return node->getChild(1);
  } else if(node->ruleType  == STATEMENT_WHILE) {
	  return node->getChild(2);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::nextStatement() {
  if(node->ruleType == STATEMENTS) {
	  return node->getChild(2);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::array() {
  if(node->ruleType == DECL) {
	  return node->getChild(1);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::exp() {
  if(node->ruleType == STATEMENT_IDENTIFIER) {
	  return node->getChild(2);

  } else if(node->ruleType == STATEMENT_WRITE) {
	  return node->getChild(1);

  } else if(node->ruleType == STATEMENT_IF) {
	  return node->getChild(1);

  } else if(node->ruleType == STATEMENT_WHILE) {
	  return node->getChild(1);

  } else if(node->ruleType == EXP2_IDENTIFIER) {
	  return node->getChild(1);

  } else if(node->ruleType == INDEX) {
	  return node->getChild(1);

  } else if(node->ruleType == OP_EXP) {
	  return node->getChild(2);

  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::exp2() {
	if(node->ruleType == EXP
	|| node->ruleType == EXP2_MINUS
	|| node->ruleType == EXP2_NEGATION) {
		return node->getChild(1);
	} else {
		node->setRuleType(RULE_NOT_SET);
		return nullptr;
  }
}

Node* Grammar::op() {
  if(node->ruleType == EXP) {
	  return node->getChild(2);

  } else if(node->ruleType == OP_EXP){
	  return node->getChild(1);

  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::index() {
	if(node->ruleType == STATEMENT_IDENTIFIER
	|| node->ruleType == STATEMENT_READ
	|| node->ruleType == EXP2_IDENTIFIER) {
	  return node->getChild(1);

  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::statement_if() {
  if(node->ruleType == STATEMENT_IF) {
	  return node->getChild(2);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}

Node* Grammar::statement_else() {
  if(node->ruleType == STATEMENT_IF) {
	  return node->getChild(3);
  } else {
	  node->setRuleType(RULE_NOT_SET);
	  return nullptr;
  }
}


