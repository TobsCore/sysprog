cmake_minimum_required(VERSION 3.6)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/List/listElement.cpp
        src/List/listElement.h
        src/Scanner/Automat/automat.cpp
        src/Scanner/Automat/automat.h
        src/Scanner/Buffer/Buffer.cpp
        src/Scanner/Buffer/Buffer.h
        src/Scanner/Scanner/scanner.cpp
        src/Scanner/Scanner/scanner.h
        src/SymbolType/symboltype.h
        src/Symtab/Container/container.cpp
        src/Symtab/Container/container.h
        src/Symtab/symtable.cpp
        src/Token/token.cpp
        src/Token/token.h)

set(SOURCE_TEST
		test/automatTest.cpp
		test/tokenTest.cpp
		test/scannerTest.cpp)

add_executable(sysprog src/main.cpp ${SOURCE_FILES})
add_executable(unitTests test/main.cpp ${SOURCE_FILES} ${SOURCE_TEST} )

target_link_libraries(sysprog)
target_link_libraries(unitTests gtest gtest_main)
