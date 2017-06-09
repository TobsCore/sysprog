//
// Created by Kevin Wolf on 08.06.17.
//

#include "Rules.h"

Rules::Rules(RuleType type) {
    this->type = type;
    this->first = this->codeFirst(type);
    this->follow = this->codeFollow(type);
}

RuleType Rules::getRuleType() {
    return this->type;
}

unsigned long long Rules::getFirst() {
    return this->first;
}

unsigned long long Rules::getFollow() {
    return this->follow;
}

void Rules::setRuleType(RuleType ruleType) {
    this->type = ruleType;
}


unsigned long long Rules::codeFirst(RuleType type) {
    switch (type) {
        case PROG:
        case DECLS1:
        case DECLS2:
        case DECL:
        case ARRAY1:
        case ARRAY2:
        case STATEMENTS1:
        case STATEMENTS2:
        case STATEMENT1:
        case STATEMENT2:
        case STATEMENT3:
        case STATEMENT4:
        case STATEMENT5:
        case STATEMENT6:
        case EXP:
        case EXP2_1:
        case EXP2_2:
        case EXP2_3:
        case EXP2_4:
        case EXP2_5:
        case INDEX1:
        case INDEX2:
        case OP_EXP1:
        case OP_EXP2:
        case OP1:
        case OP2:
        case OP3:
        case OP4:
        case OP5:
        case OP6:
        case OP7:
        case OP8:
        case OP9:
        default:
            return 0;
    }}

unsigned long long Rules::codeFollow(RuleType type) {
    switch (type) {
        case DECLS1:
        case DECLS2:
        case ARRAY1:
        case ARRAY2:
        case STATEMENTS1:
        case STATEMENTS2:
        case INDEX1:
        case INDEX2:
        case OP_EXP1:
        case OP_EXP2:
        default:
            return 0;
    }}

// ToDo man muss noch die neuen Teile der Grammatik in den Automaten adden.
// also: add return values to the cases. therefore we should discuss the given grammar in the group.