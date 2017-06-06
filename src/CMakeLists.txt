cmake_minimum_required(VERSION 3.2.3)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SCANNER_SOURCE
        main/Scanner/Position/Position.cpp
        main/Scanner/Position/Position.h
        main/Scanner/Automat/Automat.cpp
        main/Scanner/Automat/Automat.h
        main/Scanner/Buffer/Buffer.cpp
        main/Scanner/Buffer/Buffer.h
        main/Scanner/Scanner/Scanner.cpp
        main/Scanner/Scanner/Scanner.h
        main/Scanner/SymbolType/Symboltype.h
        main/Scanner/SymbolTable/Information.cpp
        main/Scanner/SymbolTable/Information.h
        main/Scanner/SymbolTable/SymbolItem.h
        main/Scanner/SymbolTable/Keyword.h
        main/Scanner/SymbolTable/SymbolTable.cpp
        main/Scanner/SymbolTable/SymbolTable.h
        main/Scanner/Token/Token.cpp
        main/Scanner/Token/Token.h
        main/Scanner/Token/IdentifierToken.cpp
        main/Scanner/Token/IdentifierToken.h
        main/Scanner/Token/IntegerToken.cpp
        main/Scanner/Token/IntegerToken.h
        main/Scanner/SymbolTable/Keywords.h
        main/Scanner/SymbolTable/StringTable/StringTable.cpp
        main/Scanner/SymbolTable/StringTable/StringTable.h
        main/String/StringOp.cpp
        main/String/StringOp.h
        main/Scanner/Token/IfToken.cpp
        main/Scanner/Token/IfToken.h
        main/Scanner/Token/WhileToken.cpp
        main/Scanner/Token/WhileToken.h
        main/Scanner/Token/ErrorToken.cpp
        main/Scanner/Token/ErrorToken.h
	    main/Scanner/Automat/State.h)

set(TEST
        test/automatTest.cpp
        test/tokenTest.cpp
        test/scannerTest.cpp
        test/bufferTest.cpp
        test/symtableTest.cpp
        test/stringTableTest.cpp
        test/scannerErrorTest.cpp)

add_executable(scanner main/Scanner/runScanner.cpp ${SCANNER_SOURCE})
add_executable(unitTests test/main.cpp ${SCANNER_SOURCE} ${TEST})

target_link_libraries(scanner)
target_link_libraries(unitTests gtest gtest_main)
