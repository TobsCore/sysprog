cmake_minimum_required(VERSION 3.5)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/lib/googletest-master)
include_directories(src/lib/googletest-master/googletest/include)
include_directories(src/lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/main/Position/Position.cpp
        src/main/Position/Position.h
        src/main/Scanner/Automat/Automat.cpp
        src/main/Scanner/Automat/Automat.h
        src/main/Scanner/Buffer/Buffer.cpp
        src/main/Scanner/Buffer/Buffer.h
        src/main/Scanner/Scanner/Scanner.cpp
        src/main/Scanner/Scanner/Scanner.h
        src/main/SymbolType/Symboltype.h
        src/main/SymbolTable/Information.cpp
        src/main/SymbolTable/Information.h
        src/main/SymbolTable/SymbolItem.h
        src/main/SymbolTable/Keyword.h
        src/main/SymbolTable/SymbolTable.cpp
        src/main/SymbolTable/SymbolTable.h
        src/main/Token/Token.cpp
        src/main/Token/Token.h
        src/main/Token/IdentifierToken.cpp
        src/main/Token/IdentifierToken.h
        src/main/Token/IntegerToken.cpp
        src/main/Token/IntegerToken.h
        src/main/SymbolTable/Keywords.h
        src/main/SymbolTable/StringTable/StringTable.cpp
        src/main/SymbolTable/StringTable/StringTable.h
        src/main/String/StringOp.cpp
        src/main/String/StringOp.h
        src/main/Token/ErrorToken.cpp
        src/main/Token/ErrorToken.h)

set(SOURCE_TEST
        src/test/automatTest.cpp
        src/test/tokenTest.cpp
        src/test/scannerTest.cpp
        src/test/bufferTest.cpp
        src/test/symtableTest.cpp
        src/test/stringTableTest.cpp src/main/Token/IfToken.cpp src/main/Token/IfToken.h src/main/Token/WhileToken.cpp src/main/Token/WhileToken.h)

add_executable(scanner src/main/main.cpp ${SOURCE_FILES})
add_executable(unitTests src/test/main.cpp ${SOURCE_FILES} ${SOURCE_TEST})

target_link_libraries(scanner)
target_link_libraries(unitTests gtest gtest_main)
