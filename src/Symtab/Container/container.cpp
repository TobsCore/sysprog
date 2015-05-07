#ifndef container
#define container
#include "container.h"
#endif

#ifndef symtype
#define symtype
#include "../../SymbolType/symboltype.h"
#endif

Container::Container() {
    this->type = 0;
    this->value = 0;
}

void Container::setValue(char* value) {
    this->value = value;
}

char* Container::getValue() {
    return this->value;
}

void Container::setType(int type) {
    this->type = type;
}

int Container::getType() {
    return this->type;
}
