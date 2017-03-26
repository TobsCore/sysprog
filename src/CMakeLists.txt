cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        List/listElement.cpp
        List/listElement.h
        Scanner/Automat/automat.cpp
        Scanner/Automat/automat.h
        Scanner/Buffer/Buffer.cpp
        Scanner/Buffer/Buffer.h
        Scanner/Scanner/scanner.cpp
        Scanner/Scanner/scanner.h
        SymbolType/symboltype.h
        Symtab/Container/container.cpp
        Symtab/Container/container.h
        Symtab/symtable.cpp
        Token/token.cpp
        Token/token.h)

add_executable(src ${SOURCE_FILES})