
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Parser.h"
#include "../main/Parser/Parser/Grammar.h"


TEST(ParserTest, ReadSimpleIntFile) {
    Parser *parser = new Parser("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = parser->parse();

    Node *root = parseTree->getTree();
    ASSERT_EQ(root->getRuleType(), PROG);
    ASSERT_EQ(root->getChild(0)->getRuleType(), DECLS);
    ASSERT_EQ(root->getChild(1)->getRuleType(), STATEMENTS_EMPTY);

    Node *decls = root->getChild(0);
    ASSERT_EQ(decls->getChild(0)->getRuleType(), DECL);
    ASSERT_EQ(decls->getChild(1)->getRuleType(), DECLS_EMPTY);

    Node *decl = decls->getChild(0);
    ASSERT_EQ(decl->getChild(0)->getRuleType(), ARRAY_EMPTY);
}

TEST(ParserTest, CheckSimplestWithGrammar) {
    Parser *parser = new Parser("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = parser->parse();

    Grammar *grammar = new Grammar();
    //grammar->typeCheck(parseTree);
}