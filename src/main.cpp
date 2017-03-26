#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Missing argument." << endl;
    } else {
        char* filePath = argv[1];
        Scanner* sc = new Scanner(filePath);

        Token token;
        while (!token.isEOF()) {
            token = sc->nextToken();
            cout << token.getTypeString() << endl;
        }
    }
    return 0;
}*/
