#include "Scanner/Scanner/Scanner.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Missing argument." << endl;
    } else {
        char *filePath = argv[1];
        Scanner *sc = new Scanner(filePath);

        Token* token = sc->nextToken();
        while (!token->isEOF()) {
            cout << token->toString() << endl;
            token = sc->nextToken();
        }
    }
    return 0;
}
