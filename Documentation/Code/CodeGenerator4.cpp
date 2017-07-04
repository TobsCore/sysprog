void CodeGenerator::generateCodeDecl(Node *node) {
	Node* array = node->getChildren(0);
	Node* identifier = node->getChildren(1);

	*outText << " DS " << "$" << static_cast<IdentifierToken*>(
		identifier->getToken())->getLexem();
	generateCode(array);
}

void CodeGenerator::generateCodeArray(Node* node) {
	Node* array = node->getChildren(0);
	*outText << " " <<array->getIntegerValue();
}
