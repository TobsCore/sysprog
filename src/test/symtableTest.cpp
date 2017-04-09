#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/SymbolTable/SymbolTable.h"

using testing::Eq;

TEST(SymtableTest, InsertTest) {
    char const *lexem = "example";

    SymbolTable *symboltable = new SymbolTable();
    SymbolItem *symbolItem;

    symbolItem = symboltable->insert(lexem);

    ASSERT_STREQ(lexem, symbolItem->lexem);
}

TEST(SymtableTest, InsertSameSymbolMultipleTimes) {
    SymbolTable *table = new SymbolTable();
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
    SymbolTable *table = new SymbolTable();
    SymbolItem *key;

    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);

    key = table->insert("b");
    ASSERT_STREQ("b", key->lexem);
}

TEST(SymtableTest, ContainsObject) {
    SymbolTable *table = new SymbolTable();
    SymbolItem *key;

    ASSERT_FALSE(table->contains("a"));
    key = table->insert("a");
    ASSERT_STREQ("a", key->lexem);
    ASSERT_TRUE(table->contains("a"));


    ASSERT_FALSE(table->contains("b"));
    key = table->insert("b");
    ASSERT_STREQ("b", key->lexem);
    ASSERT_TRUE(table->contains("b"));
}

TEST(SymtableTest, InitSymbols) {
    SymbolTable *symboltable = new SymbolTable();
    symboltable->initSymbols();

    ASSERT_TRUE(symboltable->contains("if"));
    ASSERT_TRUE(symboltable->contains("IF"));
    ASSERT_FALSE(symboltable->contains("If"));
    ASSERT_FALSE(symboltable->contains("iF"));


    ASSERT_TRUE(symboltable->contains("while"));
    ASSERT_TRUE(symboltable->contains("WHILE"));

    ASSERT_TRUE(symboltable->contains("for"));
    ASSERT_TRUE(symboltable->contains("int"));
    ASSERT_TRUE(symboltable->contains("string"));
}

TEST(SymtableTest, InsertAlphabet) {
    SymbolTable *table = new SymbolTable();
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