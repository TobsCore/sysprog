/*
#include <iostream>
#ifndef container
#define container
#include "container.h"
#endif


#ifndef symtype
#define symtype
#include "../../SymbolType/symboltype.h"
#endif

void testForValue();
void testForValue1();
void testForValueWithChange();
void testForValueWithEmptyString();
void testForValueWithNumbers();
void testPlusSign();

int main(int argc, char** argv) {
    
    testForValue();
    testForValue1();
    testForValueWithChange();
    testForValueWithEmptyString();
    testForValueWithNumbers();
    testPlusSign();
    return 0;
}

void testForValue() {
    Container* testContainer = new Container();
    char* const testValue = (char*)"x";
    testContainer->setValue(testValue);
    char* const testValueResult = testContainer->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Simple Value Succeeded!\n";
    } else {
        std::cout << "Simple Value Failed!\n";
    }
    
}

void testForValue1() {
    Container* testContainer = new Container();
    char* const testValue = (char*)"testVariableName";
    testContainer->setValue(testValue);
    char* const testValueResult = testContainer->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Advanced Value Succeeded!\n";
    } else {
        std::cout << "Advanced Value Failed!\n";
    }
    
}

void testForValueWithChange() {
    Container* testContainer = new Container();
    char* testValue = (char*)"testVariableName";
    testContainer->setValue(testValue);
    
    //Change the variable
    testValue = (char*)"testVariableNameChange";
    char* const testValueResult = testContainer->getValue();
    
    if(strcmp(testValue, testValueResult) != 0) {
        std::cout << "Value Change Succeeded!\n";
    } else {
        std::cout << "Value Change Failed!\n";
    }
    
}

void testForValueWithEmptyString() {
    Container* testContainer = new Container();
    char* const testValue = 0;
    testContainer->setValue(testValue);
    char* const testValueResult = testContainer->getValue();
    
    if(testValueResult == 0) {
        std::cout << "Empty String Succeeded!\n";
    } else {
        std::cout << "Emptry String Failed!\n";
    }
    
}


void testForValueWithNumbers() {
    Container* testContainer = new Container();
    char* const testValue = (char*)"123456";
    testContainer->setValue(testValue);
    char* const testValueResult = testContainer->getValue();
    
    if(strcmp(testValue, testValueResult) == 0) {
        std::cout << "Numbered String Succeeded!\n";
    } else {
        std::cout << "Numbered String Failed!\n";
    }
    
}


void testPlusSign() {
    Container* testContainer = new Container();
    testContainer->setType(PLUS);
    int ContainerType = testContainer->getType();

    if(ContainerType == 3 && ContainerType == PLUS) {
        std::cout << "Plus Sign Succeeded!\n";
    } else {
        std::cout << "Plus Sign Failed!\n";
    }

}*/
