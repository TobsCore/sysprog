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
        main/Scanner/Automat/State.h
        main/Scanner/Token/IfToken.cpp
        main/Scanner/Token/IfToken.h
        main/Scanner/Token/WhileToken.cpp
        main/Scanner/Token/WhileToken.h
        main/Scanner/Token/ErrorToken.cpp
        main/Scanner/Token/ErrorToken.h
        main/Scanner/Token/ReadToken.cpp
        main/Scanner/Token/ReadToken.h
        main/Scanner/Token/WriteToken.cpp
        main/Scanner/Token/WriteToken.h
        main/Scanner/Token/ElseToken.cpp
        main/Scanner/Token/ElseToken.h
        main/Scanner/Token/IntToken.cpp
        main/Scanner/Token/IntToken.h
        main/Parser/Exceptions/GrammarException.h
        main/Parser/Exceptions/CodeGenerationException.h)

set(PARSER_SOURCE
        main/Parser/Parser/Parser.h
        main/Parser/Parser/Parser.cpp
        main/Parser/Parser/Node.h
        main/Parser/Parser/Node.cpp
        main/Parser/Parser/NodeType.h
        main/Parser/Parser/RuleType.h
        main/Parser/Parser/ParseTree.cpp
        main/Parser/Parser/ParseTree.h
        main/Parser/Parser/CodeGenerator.h
        main/Parser/Parser/CodeGenerator.cpp
        main/Parser/Parser/Grammar.h
        main/Parser/Parser/Grammar.cpp
        main/Parser/Parser/TypeChecker.cpp
        main/Parser/Parser/TypeChecker.h)

set(TEST
        test/automatTest.cpp
        test/tokenTest.cpp
        test/scannerTest.cpp
        test/bufferTest.cpp
        test/symtableTest.cpp
        test/stringTableTest.cpp
        test/scannerErrorTest.cpp
        test/nodeTest.cpp
        test/newTokenTypeTest.cpp
        test/parserTest.cpp
        test/parseTreeTest.cpp)

add_executable(scanner main/Scanner/runScanner.cpp ${SCANNER_SOURCE})
add_executable(parser main/Parser/runParser.cpp ${PARSER_SOURCE} ${SCANNER_SOURCE})
add_executable(unitTests test/main.cpp ${SCANNER_SOURCE} ${PARSER_SOURCE} ${TEST})

target_link_libraries(scanner)
target_link_libraries(parser)
target_link_libraries(unitTests gtest gtest_main)
