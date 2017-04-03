#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Symtab/Symboltable.cpp"

using testing::Eq;

namespace {
    class SymtableTest : public testing::Test {
    public:
        Symboltable testSymtable;
        SymbolItem testSymItem;
    };
}

TEST_F(SymtableTest, InsertTest) {
	testSymItem = testSymtable.insert("test1");
    ASSERT_EQ(testSymItem.lexem, "test1");
}
