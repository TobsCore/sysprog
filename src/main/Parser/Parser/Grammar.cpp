/*
 * Grammar.cpp
 *
 *  Created on: 14.06.2017
 *      Author: holger
 */

#include <exception>
#include "Grammar.h"

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
void Grammar::typeCheck(Node *node) {
    this->node = node;
    switch (node->getRuleType()) {

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
            if (node->getType() != NO_TYPE) {
                node->setType(ERROR_TYPE);
                throw std::exception();
            } else {
                if (this->array() != nullptr) {
                    this->typeCheck(this->array());
                    node->setType(INT_ARRAY_TYPE);
                } else {
                    node->setType(INT_TYPE);
                }
            }
            break;

        case ARRAY:
            if (node->getIntegerValue() > 0) {
                node->setType(INT_ARRAY_TYPE);
            } else {
                node->setType(ERROR_TYPE);
                throw std::exception();
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
            if (node->getType() == NO_TYPE) {
                node->setType(ERROR_TYPE);
                throw std::exception();
            } else {
                if (!(this->exp()->getType() == INT_TYPE
                      && ((node->getType() == INT_TYPE
                           && this->index()->getType() == NO_TYPE)
                          || (node->getType() == INT_ARRAY_TYPE
                              && this->index()->getType() == INT_ARRAY_TYPE)))) {

                    node->setType(ERROR_TYPE);
                    throw std::exception();
                }
            }
            break;

        case STATEMENT_WRITE:
            this->typeCheck(this->exp());
            break;

        case STATEMENT_READ:
            this->typeCheck(this->index());
            if (node->getType() == NO_TYPE) {
                node->setType(ERROR_TYPE);
                throw std::exception();
            } else {
                if (!((node->getType() == INT_TYPE
                       && this->index()->getType() == NO_TYPE)
                      || (node->getType() == INT_ARRAY_TYPE
                          && this->index()->getType() == INT_ARRAY_TYPE))) {
                    node->setType(ERROR_TYPE);
                    throw std::exception();
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
            if (this->op()->getType() == NO_TYPE) {
                node->setType(this->exp2()->getType());
            } else if (this->op()->getType() != this->exp2()->getType()) {
                node->setType(ERROR_TYPE);
                throw std::exception();
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
            if (node->getType() == NO_TYPE) {
                node->setType(ERROR_TYPE);
                throw std::exception();
            } else if (node->getType() == INT_TYPE
                       && this->index()->getType() == NO_TYPE) {
                node->setType(node->getType());
            } else if (node->getType() == INT_ARRAY_TYPE
                       && this->index()->getType() == INT_ARRAY_TYPE) {
                node->setType(INT_TYPE);
            } else {
                node->setType(ERROR_TYPE);
                throw std::exception();
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
            if (this->exp2()->getType() != INT_TYPE) {
                node->setType(ERROR_TYPE);
                throw std::exception();
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
            throw std::exception();

        default:
            break;
    }

}

Node *Grammar::decls() {
    if (node->getRuleType() == PROG) {
        return node->getChild(1);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::decl() {
    if (node->getRuleType() == DECLS
        || node->getRuleType() == DECLS_EMPTY) {
        return node->getChild(1);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::nextDecl() {
    if (node->getRuleType() == DECLS) {
        return node->getChild(2);
    }
    throw std::exception();
}

Node *Grammar::statements() {
    if (node->getRuleType() == PROG) {
        return node->getChild(2);
    } else if (node->getRuleType() == STATEMENT_BLOCK) {
        return node->getChild(1);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::statement() {
    if (node->getRuleType() == STATEMENTS
        || node->getRuleType() == STATEMENTS_EMPTY) {
        return node->getChild(1);
    } else if (node->getRuleType() == STATEMENT_WHILE) {
        return node->getChild(2);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::nextStatement() {
    if (node->getRuleType() == STATEMENTS) {
        return node->getChild(2);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::array() {
    if (node->getRuleType() == DECL) {
        return node->getChild(1);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::exp() {
    if (node->getRuleType() == STATEMENT_IDENTIFIER) {
        return node->getChild(2);

    } else if (node->getRuleType() == STATEMENT_WRITE) {
        return node->getChild(1);

    } else if (node->getRuleType() == STATEMENT_IF) {
        return node->getChild(1);

    } else if (node->getRuleType() == STATEMENT_WHILE) {
        return node->getChild(1);

    } else if (node->getRuleType() == EXP2_IDENTIFIER) {
        return node->getChild(1);

    } else if (node->getRuleType() == INDEX) {
        return node->getChild(1);

    } else if (node->getRuleType() == OP_EXP) {
        return node->getChild(2);

    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::exp2() {
    if (node->getRuleType() == EXP
        || node->getRuleType() == EXP2_MINUS
        || node->getRuleType() == EXP2_NEGATION) {
        return node->getChild(1);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::op() {
    if (node->getRuleType() == EXP) {
        return node->getChild(2);

    } else if (node->getRuleType() == OP_EXP) {
        return node->getChild(1);

    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::index() {
    if (node->getRuleType() == STATEMENT_IDENTIFIER
        || node->getRuleType() == STATEMENT_READ
        || node->getRuleType() == EXP2_IDENTIFIER) {
        return node->getChild(1);

    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::statement_if() {
    if (node->getRuleType() == STATEMENT_IF) {
        return node->getChild(2);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}

Node *Grammar::statement_else() {
    if (node->getRuleType() == STATEMENT_IF) {
        return node->getChild(3);
    } else {
        node->setRuleType(RULE_NOT_SET);
        throw std::exception();
    }
}


