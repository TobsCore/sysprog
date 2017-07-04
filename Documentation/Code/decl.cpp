Node *Parser::decl() {
    Node *node = createNode();
    match(INTTOKEN);
    node->addChild(this->array());

    if (currentToken->getType() == IDENTIFIER) {
        node->setRuleType(DECL);
        node->addChild(createLeaf());
        nextToken();
    } else {
        printError();
    }
    return node;
}
