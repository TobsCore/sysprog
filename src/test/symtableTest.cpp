#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Symtab/Symboltable.h"

using testing::Eq;

TEST(SymtableTest, InsertTest) {
	char const *lexem = "test5";
	cout << lexem << endl;

	Symboltable* symboltable = new Symboltable();
	SymbolItem* symbolItem;

	symbolItem = symboltable->insert(lexem);
	symboltable->viewStringTable();

	ASSERT_EQ(*(symbolItem->lexem), *lexem);
}
