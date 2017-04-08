#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Symtab/Symboltable.h"

using testing::Eq;

TEST(SymtableTest, InsertTest) {
    char const *lexem = "example";

    Symboltable *symboltable = new Symboltable();
    SymbolItem *symbolItem;

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

TEST(SymtableTest, InsertAlphabet) {
    Symboltable *table = new Symboltable();
    SymbolItem *key;

    const char *val;
    const char *letter[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                            "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int i = 0; i < 100; i++) {
        val = letter[i % 26];
        key = table->insert(val);
        ASSERT_STREQ(val, key->lexem);
    }
}