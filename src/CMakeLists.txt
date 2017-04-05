cmake_minimum_required(VERSION 3.5)
project(sysprog)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        main/List/listElement.cpp
        main/List/listElement.h
        main/Position/Position.cpp
        main/Position/Position.h
		main/Scanner/Automat/automat.cpp
		main/Scanner/Automat/automat.h
		main/Scanner/Buffer/Buffer.cpp
		main/Scanner/Buffer/Buffer.h
		main/Scanner/Scanner/scanner.cpp
		main/Scanner/Scanner/scanner.h
		main/SymbolType/symboltype.h
		main/Symtab/Container/container.cpp
		main/Symtab/Container/container.h
		main/Symtab/symtable.cpp
        main/Symtab/Information.cpp
        main/Symtab/Information.h
        main/Symtab/SymbolItem.h
        main/Symtab/Keyword.h
        main/Symtab/Symboltable.cpp
        main/Symtab/Symboltable.h
		main/Token/token.cpp
		main/Token/token.h)

set(SOURCE_TEST
	test/automatTest.cpp
	test/tokenTest.cpp
	test/scannerTest.cpp
    test/bufferTest.cpp
    test/symtableTest.cpp)

add_executable(sysprogMain main/main.cpp ${SOURCE_FILES})
add_executable(unitTests test/main.cpp ${SOURCE_FILES} ${SOURCE_TEST} )

target_link_libraries(sysprogMain)
target_link_libraries(unitTests gtest gtest_main)
