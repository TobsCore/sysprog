cmake_minimum_required(VERSION 3.5)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        main/Position/Position.cpp
        main/Position/Position.h
        main/Scanner/Automat/Automat.cpp
        main/Scanner/Automat/Automat.h
        main/Scanner/Buffer/Buffer.cpp
        main/Scanner/Buffer/Buffer.h
        main/Scanner/Scanner/Scanner.cpp
        main/Scanner/Scanner/Scanner.h
        main/SymbolType/Symboltype.h
        main/SymbolTable/Information.cpp
        main/SymbolTable/Information.h
        main/SymbolTable/SymbolItem.h
        main/SymbolTable/Keyword.h
        main/SymbolTable/SymbolTable.cpp
        main/SymbolTable/SymbolTable.h
        main/Token/Token.cpp
        main/Token/Token.h
        main/Token/IdentifierToken.cpp
        main/Token/IdentifierToken.h
        main/Token/IntegerToken.cpp
        main/Token/IntegerToken.h
        main/SymbolTable/Keywords.h
        main/SymbolTable/StringTable/StringTable.cpp
        main/SymbolTable/StringTable/StringTable.h
        main/String/StringOp.cpp
        main/String/StringOp.h
        main/src/main/Token/ErrorToken.cpp
        main/src/main/Token/ErrorToken.h)

set(SOURCE_TEST
        test/automatTest.cpp
        test/tokenTest.cpp
        test/scannerTest.cpp
        test/bufferTest.cpp
        test/symtableTest.cpp
        test/stringTableTest.cpp)

add_executable(sysprogMain main/main.cpp ${SOURCE_FILES})
add_executable(unitTests test/main.cpp ${SOURCE_FILES} ${SOURCE_TEST})

target_link_libraries(sysprogMain)
target_link_libraries(unitTests gtest gtest_main)
