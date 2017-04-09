cmake_minimum_required(VERSION 3.5)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/lib/googletest-master)
include_directories(src/lib/googletest-master/googletest/include)
include_directories(src/lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/main/Position/Position.cpp
        src/main/Position/Position.h
        src/main/Scanner/Automat/automat.cpp
        src/main/Scanner/Automat/automat.h
        src/main/Scanner/Buffer/Buffer.cpp
        src/main/Scanner/Buffer/Buffer.h
        src/main/Scanner/Scanner/scanner.cpp
        src/main/Scanner/Scanner/scanner.h
        src/main/SymbolType/symboltype.h
        src/main/Symtab/Information.cpp
        src/main/Symtab/Information.h
        src/main/Symtab/SymbolItem.h
        src/main/Symtab/Keyword.h
        src/main/Symtab/Symboltable.cpp
        src/main/Symtab/Symboltable.h
        src/main/Token/Token.cpp
        src/main/Token/Token.h
        src/main/Token/IdentifierToken.cpp
        src/main/Token/IdentifierToken.h
        src/main/Token/IntegerToken.cpp
        src/main/Token/IntegerToken.h
        src/main/Symtab/Keywords.h)

set(SOURCE_TEST
        src/test/automatTest.cpp
        src/test/tokenTest.cpp
        src/test/scannerTest.cpp
        src/test/bufferTest.cpp
        src/test/symtableTest.cpp)

add_executable(sysprogMain src/main/main.cpp ${SOURCE_FILES})
add_executable(unitTests src/test/main.cpp ${SOURCE_FILES} ${SOURCE_TEST})

target_link_libraries(sysprogMain)
target_link_libraries(unitTests gtest gtest_main)
