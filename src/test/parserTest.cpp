
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Parser.h"
#include "../main/Parser/Parser/SemanticAnalyser.h"
#include "../main/Parser/Parser/Compiler.h"


TEST(ParserTest, DISABLED_ReadSimpleIntFile) {
    //TODO(Toby): Fix Tests
/*    Parser *parser = new Compiler("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = parser->parse();

    Node *root = parseTree->getTree();
    ASSERT_EQ(root->getRuleType(), PROG);
    ASSERT_EQ(root->getChild(0)->getRuleType(), DECLS);
    ASSERT_EQ(root->getChild(1)->getRuleType(), STATEMENTS_EMPTY);
    ASSERT_FALSE(root->isLeaf());

    Node *decls = root->getChild(0);
    ASSERT_EQ(decls->getChild(0)->getRuleType(), DECL);
    ASSERT_EQ(decls->getChild(1)->getRuleType(), DECLS_EMPTY);
    ASSERT_FALSE(decls->isLeaf());

    Node *decl = decls->getChild(0);
    ASSERT_EQ(decl->getChild(0)->getRuleType(), ARRAY_EMPTY);
    ASSERT_EQ(decl->getAmountOfChildren(), 2);
    ASSERT_FALSE(decl->isLeaf());

    ASSERT_TRUE(decl->getChild(0)->isLeaf());*/
}

TEST(ParserTest, DISABLED_CheckSimplestWithGrammar) {
    //TODO(Toby): Fix Tests
/*    Parser *parser = new Parser("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = parser->parse();

    TypeChecker *analyzer = new TypeChecker();
    ASSERT_NO_THROW(analyzer->run(parseTree));

    CodeGenerator *codeGenerator = new CodeGenerator("out.code");
    ASSERT_NO_THROW(codeGenerator->run(parseTree));*/
}

TEST(ParserTest, DISABLED_SimplestAddition) {
    //TODO(Toby): Fix tests
   /* Parser *parser = new Parser("../src/test/testData/programs/simplestAddition.txt", "testout.txt");
    ParseTree *parseTree = parser->parse();

    TypeChecker *analyzer = new TypeChecker();
    ASSERT_NO_THROW(analyzer->run(parseTree));

    CodeGenerator *codeGenerator = new CodeGenerator("out.code");
    ASSERT_NO_THROW(codeGenerator->run(parseTree));*/
}