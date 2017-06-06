cmake_minimum_required(VERSION 3.2.3)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/lib/googletest)
include_directories(src/lib/googletest/googletest/include)
include_directories(src/lib/googletest/googlemock/include)

set(SCANNER_SOURCE
        src/main/Scanner/Position/Position.cpp
        src/main/Scanner/Position/Position.h
        src/main/Scanner/Automat/Automat.cpp
        src/main/Scanner/Automat/Automat.h
        src/main/Scanner/Buffer/Buffer.cpp
        src/main/Scanner/Buffer/Buffer.h
        src/main/Scanner/Scanner/Scanner.cpp
        src/main/Scanner/Scanner/Scanner.h
        src/main/Scanner/SymbolType/Symboltype.h
        src/main/Scanner/SymbolTable/Information.cpp
        src/main/Scanner/SymbolTable/Information.h
        src/main/Scanner/SymbolTable/SymbolItem.h
        src/main/Scanner/SymbolTable/Keyword.h
        src/main/Scanner/SymbolTable/SymbolTable.cpp
        src/main/Scanner/SymbolTable/SymbolTable.h
        src/main/Scanner/Token/Token.cpp
        src/main/Scanner/Token/Token.h
        src/main/Scanner/Token/IdentifierToken.cpp
        src/main/Scanner/Token/IdentifierToken.h
        src/main/Scanner/Token/IntegerToken.cpp
        src/main/Scanner/Token/IntegerToken.h
        src/main/Scanner/SymbolTable/Keywords.h
        src/main/Scanner/SymbolTable/StringTable/StringTable.cpp
        src/main/Scanner/SymbolTable/StringTable/StringTable.h
        src/main/String/StringOp.cpp
        src/main/String/StringOp.h
        src/main/Scanner/Token/IfToken.cpp
        src/main/Scanner/Token/IfToken.h
        src/main/Scanner/Token/WhileToken.cpp
        src/main/Scanner/Token/WhileToken.h
        src/main/Scanner/Token/ErrorToken.cpp
        src/main/Scanner/Token/ErrorToken.h
	src/main/Scanner/Automat/State.h)

set(TEST
        src/test/automatTest.cpp
        src/test/tokenTest.cpp
        src/test/scannerTest.cpp
        src/test/bufferTest.cpp
        src/test/symtableTest.cpp
        src/test/stringTableTest.cpp
        src/test/scannerErrorTest.cpp)

add_executable(scanner src/main/Scanner/runScanner.cpp ${SCANNER_SOURCE})
add_executable(unitTests src/test/main.cpp ${SCANNER_SOURCE} ${TEST})

target_link_libraries(scanner)
target_link_libraries(unitTests gtest gtest_main)
