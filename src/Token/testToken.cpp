#include <iostream>
#ifndef token
#define token
#include "token.h"
#endif

void simpletest();
void testDifferentTypes();
void testForValue();
void testForValue1();
void testForValueWithEmptyString();
void testForValueWithNumbers();

int main(int argc, char** argv) {
    
    simpletest();
    testDifferentTypes();
    testForValue();
    testForValue1();
    testForValueWithEmptyString();
    testForValueWithNumbers();
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

void testForValue() {
    Token* testToken = new Token();
    char* const testValue = (char*)"x";
    testToken->setValue(testValue);
    char* const testValueResult = testToken->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Simple Value Succeeded!\n";
    } else {
        std::cout << "Simple Value Failed!\n";
    }
    
}

void testForValue1() {
    Token* testToken = new Token();
    char* const testValue = (char*)"testVariableName";
    testToken->setValue(testValue);
    char* const testValueResult = testToken->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Advanced Value Succeeded!\n";
    } else {
        std::cout << "Advanced Value Failed!\n";
    }
    
}

void testForValueWithEmptyString() {
    Token* testToken = new Token();
    char* const testValue = 0;
    testToken->setValue(testValue);
    char* const testValueResult = testToken->getValue();
    
    if(testValueResult == 0) {
        std::cout << "Empty String Succeeded!\n";
    } else {
        std::cout << "Emptry String Failed!\n";
    }
    
}


void testForValueWithNumbers() {
    Token* testToken = new Token();
    char* const testValue = (char*)"123456";
    testToken->setValue(testValue);
    char* const testValueResult = testToken->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Numbered String Succeeded!\n";
    } else {
        std::cout << "Numbered String Failed!\n";
    }
    
}
