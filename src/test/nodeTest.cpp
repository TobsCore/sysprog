#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Node.h"
#include "../main/Scanner/SymbolTable/SymbolTable.h"
#include "../main/Scanner/Token/IntegerToken.h"


using testing::Eq;

namespace {
    class NodeTest : public testing::Test {
    public:
        Node node;
    };
}

TEST_F(NodeTest, DISABLED_AddNoNode) {
  /*  ASSERT_THROW(node.getChild(0), std::out_of_range);
    ASSERT_THROW(node.getChild(1), std::out_of_range);*/
}

TEST_F(NodeTest, DISABLED_AddOneNode) {
/*    Node *insertNode = new Node();

    node.addChild(insertNode);
    ASSERT_EQ(insertNode, node.getChild(0));*/
}

TEST_F(NodeTest, DISABLED_AddMaxNodes) {
 /*   for (int i = 0; i < UCHAR_MAX; i++) {
        Node *insertNode = new Node();
        node.addChild(insertNode);
        ASSERT_EQ(insertNode, node.getChild(i));
    }*/
}

TEST_F(NodeTest, DISABLED_AddMaxNodesPLUSONE) {
 /*   for (int i = 0; i < UCHAR_MAX; i++) {
        node.addChild(new Node());
    }
    ASSERT_THROW(node.addChild(new Node), std::out_of_range);*/
}

TEST_F(NodeTest, DISABLED_IsLeafForNewlyCreatedNode) {
    ASSERT_TRUE(node.isLeaf());
}

TEST_F(NodeTest, DISABLED_IsLeafAfterAddingChil) {
   /* node.addChild(new Node());
    ASSERT_FALSE(node.isLeaf());*/
}

TEST_F(NodeTest, DISABLED_DeleteNode) {
/*    Node *deleteNode = new Node();
    deleteNode->setType(NodeType::INT_TYPE);
    deleteNode->setToken(new IntegerToken());

    delete deleteNode;*/
}
