#include <iostream>
#ifndef token
#define token
#include "token.h"
#endif

void simpletest();
void testDifferentTypes();

int main(int argc, char** argv) {
    
    simpletest();
    testDifferentTypes();
    return 0;
}

void simpletest() {
    Token* testToken = new Token();
    testToken->setRow(5);
    testToken->setColumn(1);
    testToken->setType(1);
    int row = testToken->getRow();
    int col = testToken->getColumn();
    int type = testToken->getType();
    
    if(row == 5 && col == 1 && type == 1) {
        std::cout << "Simple-Test Succeeded!\n";
    } else {
        std::cout << "Simple Test Failed!\n";
    }
    
}

void testDifferentTypes() {
    Token* testToken = new Token();
    testToken->setType(-1);
    int type = testToken->getType();
    
    if(type == -1) {
        std::cout << "Error-Type Succeeded!\n";
    } else {
        std::cout << "Error-Type Failed!\n";
    }
    
}