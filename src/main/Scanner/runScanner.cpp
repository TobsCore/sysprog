#include <fstream>
#include "Scanner/Scanner.h"
#include "../colors.h"

void clearOutputFile(const char *outFilename) {
    ofstream ofs;
    ofs.open(outFilename, std::ofstream::out | std::ofstream::trunc);
    if (!ofs.is_open()) {
        cerr << "\033[1;31m" << "Error!" << "\033[0m" << " Cannot write to output file <" << outFilename << ">"
             << endl;
        exit(EXIT_FAILURE);
    }
    ofs.close();
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage:" << endl << "scanner <inputfile> <outputfile>" << endl;
        return 1;
    }

    const char *inFile = argv[1];
    const char *outFilename = argv[2];
    try {
        Scanner *sc = new Scanner(inFile);

        // Clear output file
        clearOutputFile(outFilename);

        // Creates file appender for output file
        ofstream result(outFilename, std::ios_base::app);
        cout << "Running..." << endl;

        Token *token = sc->nextToken();
        while (!token->isEOF()) {
            if (token->getType() == ERROR) {
                cerr << RED << token->toString() << COLOR_RESET << endl;
            } else {
                if (result.is_open()) {
                    result << token->toString() << endl;
                } else {
                    cerr << RED << "Error!" << COLOR_RESET << " Cannot write to output file <" << outFilename <<
                         ">"
                         << endl;
                    exit(EXIT_FAILURE);
                }
            }

            token = sc->nextToken();
        }

        cout << GREEN << "Finished!" << COLOR_RESET << endl << "Output written to <" << outFilename << ">" <<
             endl;
        result.close();

    } catch (std::exception &ex) {
        cerr << RED << "Error! " << COLOR_RESET << "Cannot read input file <" << inFile << ">" << endl;
        exit(EXIT_FAILURE);

    }
    return 0;
}
