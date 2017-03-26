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
        src/Token/token.h 
		src/main.cpp
		test/automatTest.cpp
		test/tokenTest.cpp)

add_executable(sysprog ${SOURCE_FILES})
target_link_libraries(sysprog gtest gtest_main)
