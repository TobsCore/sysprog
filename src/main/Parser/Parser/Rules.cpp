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
    //noch zu tun
}

unsigned long long Rules::codeFollow(RuleType type) {
    //noch zu tun
}

//ToDo man muss noch die neuen Teile der Grammatik in den Automaten adden.