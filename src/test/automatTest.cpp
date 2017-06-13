#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Automat/Automat.h"

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
    ASSERT_EQ(testAutomat.checkExpression(' '), INTTOKEN);
    ASSERT_EQ(testAutomat.checkExpression('v'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, IfStatement) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('('), IFTOKEN);
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

TEST_F(AutomatTest, Assignment) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), INTTOKEN);
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

TEST_F(AutomatTest, Special) {
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

TEST_F(AutomatTest, SpecialNotFulfilled) {
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), ERROR_SPECIAL);
    ASSERT_EQ(testAutomat.checkExpression('+'), COLON);
    ASSERT_EQ(testAutomat.checkExpression('\0'), PLUS);
}

TEST_F(AutomatTest, SpecialTwice) {
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), SPECIAL);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SPECIAL);
}

TEST_F(AutomatTest, Array) {
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

TEST_F(AutomatTest, ComplexBoolean) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('('), IFTOKEN);
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

TEST_F(AutomatTest, NewLine) {
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

TEST_F(AutomatTest, TrailingSpaces) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(' '), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), NEXTCHAR);
}

TEST_F(AutomatTest, TrailingNewLine) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\n'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('\0'), NEXTCHAR);
}

TEST_F(AutomatTest, PrecedingSpaces) {
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

TEST_F(AutomatTest, CloseArithmaticExpression) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}

TEST_F(AutomatTest, NotAComment) {
    ASSERT_EQ(testAutomat.checkExpression('+'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), PLUS);
    ASSERT_EQ(testAutomat.checkExpression('\0'), EQUALS);
}

TEST_F(AutomatTest, ShortestComment) {
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, CommentWithStars) {
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, CommentWithSpaces) {
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, CommentWithEverythingBetween) {
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('c'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('='), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, CommentWithSomethingBefore) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('b'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression('\0'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(' '), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, CommentWithSomethingAfter) {
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('c'), COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('='), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), EQUALS);
}

TEST_F(AutomatTest, CommentWithSomethingAfterAndBefore) {
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, IfTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), IFTOKEN);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, IfTokenTest2withoutif) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, WhileTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), WHILETOKEN);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, WhileTokenTest2) {
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('w'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), WHILETOKEN);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, WhileStatement) {
    ASSERT_EQ(testAutomat.checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('('), WHILETOKEN);
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

TEST_F(AutomatTest, NoIfNoWhile) {
    ASSERT_EQ(testAutomat.checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, ErroneousSymbols) {
    ASSERT_EQ(testAutomat.checkExpression('!'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('&'), EXCLAMATION);
    ASSERT_EQ(testAutomat.checkExpression(','), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('&'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('a'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('#'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), ERROR);
}


TEST_F(AutomatTest, ErroneousSymbols2) {
    ASSERT_EQ(testAutomat.checkExpression(','), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('j'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression(','), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), ERROR);
}

TEST_F(AutomatTest, ErroneousSymbols3) {
    ASSERT_EQ(testAutomat.checkExpression(','), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(','), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('&'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), ERROR);
}


TEST_F(AutomatTest, ErroneousSymbols4) {
    ASSERT_EQ(testAutomat.checkExpression('!'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('&'), EXCLAMATION);
    ASSERT_EQ(testAutomat.checkExpression('$'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('&'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('a'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('$'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), ERROR);
}

TEST_F(AutomatTest, CheckComment) {
    ASSERT_EQ(testAutomat.checkExpression('D'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('s'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('s'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('1'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('1'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('1'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('1'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(' '), COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('K'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('o'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('m'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('m'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), IDENTIFIER);
}


TEST_F(AutomatTest, CheckDot) {
    ASSERT_EQ(testAutomat.checkExpression('1'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('2'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('.'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('3'), ERROR);
    ASSERT_EQ(testAutomat.checkExpression('\0'), INTEGER);

}

TEST_F(AutomatTest, ReadTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('d'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), READTOKEN);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, WriteTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), WRITETOKEN);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, ElseTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('s'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(':'), ELSETOKEN);
    ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
    ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
    ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
    ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
    ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, NoWriteNoReadNoElse) {
ASSERT_EQ(testAutomat.checkExpression('w'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('s'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('a'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('d'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression(':'), IDENTIFIER);
ASSERT_EQ(testAutomat.checkExpression('='), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('b'), ASSIGN);
ASSERT_EQ(testAutomat.checkExpression('+'), IDENTIFIER);
ASSERT_EQ(testAutomat.checkExpression('c'), PLUS);
ASSERT_EQ(testAutomat.checkExpression(';'), IDENTIFIER);
ASSERT_EQ(testAutomat.checkExpression(':'), SEMICOLON);
ASSERT_EQ(testAutomat.checkExpression('*'), NEXTCHAR);
ASSERT_EQ(testAutomat.checkExpression('a'), IN_COMMENT);
ASSERT_EQ(testAutomat.checkExpression('+'), IN_COMMENT);
ASSERT_EQ(testAutomat.checkExpression('b'), IN_COMMENT);
ASSERT_EQ(testAutomat.checkExpression('*'), IN_COMMENT);
ASSERT_EQ(testAutomat.checkExpression(':'), IN_COMMENT);
ASSERT_EQ(testAutomat.checkExpression('\0'), COMMENT);
}

TEST_F(AutomatTest, IntTokenTest1) {
    ASSERT_EQ(testAutomat.checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('n'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(' '), INTTOKEN);
    ASSERT_EQ(testAutomat.checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('o'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('b'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('s'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression('='), IDENTIFIER);
    ASSERT_EQ(testAutomat.checkExpression('8'), EQUALS);
    ASSERT_EQ(testAutomat.checkExpression('8'), NEXTCHAR);
    ASSERT_EQ(testAutomat.checkExpression(';'), INTEGER);
    ASSERT_EQ(testAutomat.checkExpression('\0'), SEMICOLON);
}


