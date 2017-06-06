/*
 * Information.cpp
 *
 *  Created on: 03.05.2015
 *      Author: holger
 */

#include <iostream>

#include "Information.h"


using namespace std;

Information::Information() {
    this->type = IDENTIFIER;
    this->name = NULL;
    this->keyword = NOKEYWORD;
}

Information::Information(const char *name) {
    this->type = IDENTIFIER;
    this->name = name;
    this->keyword = this->isKeyword();
}

void Information::setName(const char *other) {
    this->name = other;
    if (this->name != NULL && this->type != 0) {
        this->keyword = this->isKeyword();
    }
}

int Information::nameLength() {
    int i = 0;
    while (this->name[i] != '\0') {
        i++;
    }
    return i;
}

Keyword Information::isKeyword() {
    if (this->type == IDENTIFIER) {
        int length = this->nameLength();
        int i = 0;
        if (length == 2) {
            char ifType[] = "if";
            while (this->name[i] != '\0') {
                if (this->name[i] != ifType[i]) {
                    return NOKEYWORD;
                }
                i++;
            }
            return IF;
        } else if (length == 5) {
            char whileType[] = "while";
            while (this->name[i] != '\0') {
                if (this->name[i] != whileType[i]) {
                    return NOKEYWORD;
                }
                i++;
            }
            return WHILE;
        }
    }
    return NOKEYWORD;
}

Information::~Information() {
}
