
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Parser.h"
#include "../main/Parser/Parser/SemanticAnalyser.h"
#include "../main/Parser/Parser/Compiler.h"


TEST(ParserTest, ReadSimpleIntFile) {

	Compiler *compiler = new Compiler("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = compiler->parser->parse();

    Node *root = parseTree->getTree();
    ASSERT_EQ(root->getRuleType(), PROG);
    ASSERT_EQ(root->getChildren(0)->getRuleType(), DECLS);
    ASSERT_EQ(root->getChildren(1)->getRuleType(), STATEMENTS_2);
    ASSERT_FALSE(root->isLeaf());

    Node *decls = root->getChildren(0);
    ASSERT_EQ(decls->getChildren(0)->getRuleType(), DECL);
    ASSERT_EQ(decls->getChildren(1)->getRuleType(), DECLS_2);
    ASSERT_FALSE(decls->isLeaf());

    Node *decl = decls->getChildren(0);
    ASSERT_EQ(decl->getChildren(0)->getRuleType(), ARRAY_2);
    ASSERT_EQ(decl->currentChildren, 2);
    ASSERT_FALSE(decl->isLeaf());

    ASSERT_TRUE(decl->getChildren(1)->isLeaf());
}

TEST(ParserTest, CheckSimplestWithGrammar) {
    //TODO(Toby): Fix Tests
	Compiler *compiler = new Compiler("../src/test/testData/programs/simplestProgram.txt", "testout.txt");
    ParseTree *parseTree = compiler->parser->parse();

    SemanticAnalyser *analyzer = new SemanticAnalyser();
    ASSERT_NO_THROW(analyzer->typeCheck(parseTree));

    Node *root = parseTree->getTree();
    CodeGenerator *codeGenerator = new CodeGenerator("out.code");
    ASSERT_NO_THROW(codeGenerator->runCodeGenerator(root));
}

TEST(ParserTest, SimplestAddition) {
    //TODO(Toby): Fix tests
	Compiler *compiler = new Compiler("../src/test/testData/programs/simplestAddition.txt", "testout.txt");
    ParseTree *parseTree = compiler->parser->parse();

    SemanticAnalyser *analyzer = new SemanticAnalyser();
    analyzer->typeCheck(parseTree);

    Node *root = parseTree->getTree();
    CodeGenerator *codeGenerator = new CodeGenerator("out.code");
    ASSERT_NO_THROW(codeGenerator->runCodeGenerator(root));
}
