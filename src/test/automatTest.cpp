#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Automat/automat.h"

using testing::Eq;

namespace {
    class AutomatTest : public testing::Test {
    public:
        Automat testAutomat;
    };
}

TEST_F(AutomatTest, IntegerAddition) {
    ASSERT_EQ(testAutomat.checkExpression('1'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('2'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('3'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('4'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('5'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression('2'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, VariableIdentification) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, ifStatement) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('('), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('v'), PARANTHESES_LEFT);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('1'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), EQUALS);
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('2'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(')'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('{'), PARANTHESES_RIGHT);
    ASSERT_EQ(testAutomat.checkExpression('\n'), BRACES_LEFT);
    ASSERT_EQ(testAutomat.checkExpression('}'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), BRACES_RIGHT);
}

TEST_F(AutomatTest, assignment) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), ASSIGN);   // EQUALS
    ASSERT_EQ(testAutomat.checkExpression('3'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('5'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, special) {
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), SPECIAL);
    ASSERT_EQ(testAutomat.checkExpression('3'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('5'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, specialError) {
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), PLUS);
}

TEST_F(AutomatTest, array) {
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('['), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('5'), BRACKET_LEFT);
    ASSERT_EQ(testAutomat.checkExpression('6'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(']'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression(' '), BRACKET_RIGHT);
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('2'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), SPECIAL);
    ASSERT_EQ(testAutomat.checkExpression('3'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('5'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, complexBoolean) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('('), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('a'), PARANTHESES_LEFT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), EQUALS);
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), AND);
    ASSERT_EQ(testAutomat.checkExpression('!'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), EXCLAMATION);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), EQUALS);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), AND);
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('<'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), LESS);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('&'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), AND);
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('>'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), GREATER);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(')'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(';'), PARANTHESES_RIGHT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, newLine) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('b'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\n'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression('\0'), IDENTIFIER);
}

TEST_F(AutomatTest, trailingSpaces) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(' '), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), NEXTCHAR);
}

TEST_F(AutomatTest, trailingNewLine) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\n'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('\0'), NEXTCHAR);
}

TEST_F(AutomatTest, precedingSpaces) {
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, EOFinMiddle) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('b'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression('\0'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}
