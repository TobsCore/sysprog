#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/SymbolTable/SymbolTable.h"

using testing::Eq;

TEST(SymtableTest, Insert) {
    char const *lexem = "example";

    SymbolTable *symboltable = new SymbolTable();
    SymbolItem *symbolItem;

    symbolItem = symboltable->insert(lexem);

    ASSERT_STREQ(lexem, symbolItem->lexem);
    delete symboltable;
}

TEST(SymtableTest, InsertSameSymbolMultipleTimes) {
    SymbolTable *table = new SymbolTable();
    SymbolItem *key1;
    SymbolItem *key2;

    key1 = table->insert("a");
    ASSERT_STREQ("a", key1->lexem);

    key2 = table->insert("a");
    ASSERT_STREQ("a", key2->lexem);

    //Checks, that they are at the same position. This is important, so the keys aren't placed twice in the symbol
    // table.
    ASSERT_EQ(key1, key2);
    ASSERT_STREQ(key1->lexem, key2->lexem);

    delete table;
}

TEST(SymtableTest, InsertTwoDifferentSymbols) {
    SymbolTable *table = new SymbolTable();
    SymbolItem *key;

    key = table->insert("example1");
    ASSERT_STREQ("example1", key->lexem);

    key = table->insert("example2");
    ASSERT_STREQ("example2", key->lexem);

    key = table->insert("example3");
    ASSERT_STREQ("example3", key->lexem);
    delete table;
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
    delete table;
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
    delete symboltable;
}

TEST(SymtableTest, InsertAlphabet) {
    SymbolTable *table = new SymbolTable();

    const char *letter[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                            "s", "t", "u", "v", "w", "x", "y", "z"};
    for (int i = 0; i < 100; i++) {
        const char *val = letter[i % 26];
        SymbolItem *key = table->insert(val);
        ASSERT_STREQ(val, key->lexem);
    }
    delete table;
}
