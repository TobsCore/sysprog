#include "Scanner/Scanner/scanner.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Missing argument." << endl;
    } else {
        char *filePath = argv[1];
        Scanner *sc = new Scanner(filePath);

        Token token;
        while (!token.isEOF()) {
            token = sc->nextToken();
            cout << token.getTypeString() << endl;
        }
    }
    return 0;
}
