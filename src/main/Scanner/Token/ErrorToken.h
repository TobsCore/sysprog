//
// Created by Tobias Kerst on 11.05.17.
//
#include "Token.h"

class ErrorToken : public Token {

public:
    ErrorToken();

    const char *toString();

    const char *getInfo();

    void setInfo(const char *info);

private:
    const char *info;
};