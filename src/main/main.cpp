#include <fstream>
#include "Scanner/Scanner/Scanner.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "Missing arguments." << endl;
    } else {
        const char *inFile = argv[1];
        const char *outFilename = argv[2];
        Scanner *sc = new Scanner(inFile);


        // Clear output file
        ofstream ofs;
        ofs.open(outFilename, std::ofstream::out | std::ofstream::trunc);
        ofs.close();

        // Creates file appender for output file
        ofstream result(outFilename, std::ios_base::app);
        cout << "Running..." << endl;

        Token *token = sc->nextToken();
        while (!token->isEOF()) {
            if (token->getType() == ERROR) {
                cerr << "\033[1;31m" << token->toString() << "\033[0m" << endl;
            } else {
                if (result.is_open()) {
                    result << token->toString() << endl;
                } else {
                    cerr << "Cannot write to file <" << outFilename << ">" << endl;
                    break;
                }
            }

            token = sc->nextToken();
        }

        cout << "\033[1;32m" << "Finished!" << "\033[0m" << endl << "Output written to <" << outFilename << ">" <<
             endl;
        result.close();
    }
    return 0;
}
