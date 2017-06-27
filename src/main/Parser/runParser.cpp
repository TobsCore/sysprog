#include <fstream>
#include "../colors.h"
#include "../Scanner/Scanner/Scanner.h"
#include "Parser/Parser.h"
#include "Parser/Compiler.h"

void clearOutputFile(const char* outFilename) {
    ofstream ofs;
    ofs.open(outFilename, std::ofstream::out | std::ofstream::trunc);
    if (!ofs.is_open()) {
        cerr << RED << "Error!" << COLOR_RESET << " Cannot write to output file <" << outFilename << ">"
             << endl;
        exit(EXIT_FAILURE);
    }
    ofs.close();
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage:" << endl << "parser <inputfile> <outputfile>" << endl;
        return 1;
    }

    const char *inFilename = argv[1];
    const char *outFilename = argv[2];
    try {
        Compiler* compiler = new Compiler (inFilename, outFilename);

        cout << "Parsing..." << endl;
        compiler->parse();

        cout << "Checking type information.." << endl;
        compiler->typeCheck();

        cout << "Generating code.." << endl;
        compiler->runCodeGenerator();


    } catch (std::exception &ex) {
        cerr << RED << "Error! " << COLOR_RESET << "Cannot read input file <" << inFilename << ">" << endl;
        exit(EXIT_FAILURE);

    }
    return 0;
}
