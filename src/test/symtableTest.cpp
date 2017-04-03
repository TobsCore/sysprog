#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Symtab/Symboltable.h"

using testing::Eq;

TEST(SymtableTest, InsertTest) {
    SymbolItem *testSymItem;
    Symboltable *testSymtable = new Symboltable();
	testSymItem = testSymtable->insert("test1");
    ASSERT_EQ(testSymItem->lexem, "test1");
}
