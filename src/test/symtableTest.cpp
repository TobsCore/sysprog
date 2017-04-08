#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Symtab/Symboltable.h"

using testing::Eq;

TEST(SymtableTest, InsertTest) {
    char const *lexem = "example";

	Symboltable* symboltable = new Symboltable();
	SymbolItem* symbolItem;

	symbolItem = symboltable->insert(lexem);

	ASSERT_STREQ(lexem, symbolItem->lexem);
}

TEST(SymtableTest, InsertSameSymbolMultipleTimes) {
    Symboltable *table = new Symboltable();
    SymbolItem *key;

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

}

TEST(SymtableTest, InsertTwoDifferentSymbols) {
    Symboltable *table = new Symboltable();
    SymbolItem *key;

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

    key = table->insert("b");
    ASSERT_STREQ("b", key->lexem);
}