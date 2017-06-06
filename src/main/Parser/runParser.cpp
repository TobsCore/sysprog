#include <fstream>
#include "../Scanner/Scanner/Scanner.h"

void clearOutputFile(const char* outFilename) {
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
    if (argc != 4) {
        cerr << "usage:" << endl << "parser <inputfile> -c <outputfile>" << endl;
        return 1;
    }

    const char *inFile = argv[1];
    const char *outFilename = argv[3];
    try {
        Scanner *sc = new Scanner(inFile);

        // Clear output file
        clearOutputFile(outFilename);

        // Creates file appender for output file
        ofstream result(outFilename, std::ios_base::app);

        //TODO: Insert Parser execution code here

        result.close();

    } catch (std::exception &ex) {
        cerr << "\033[1;31m" << "Error! " << "\033[0m" << "Cannot read input file <" << inFile << ">" << endl;
        exit(EXIT_FAILURE);

    }
    return 0;
}
