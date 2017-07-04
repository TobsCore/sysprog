void CodeGenerator::runCodeGenerator(ParseTree *parseTree) {
	Node *root = parseTree->getTree();
	generateCodeProg(root);
	*codeFile << outText->rdbuf();
	codeFile->flush();
	outText->str(string());
}
