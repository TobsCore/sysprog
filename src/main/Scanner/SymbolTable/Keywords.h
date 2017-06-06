//
// Created by Tobias Kerst on 09.04.17.
//

#ifndef SYSPROG_KEYWORDS_H
#define SYSPROG_KEYWORDS_H


static const char *KEYWORDS[] = {"abstract", "assert", "boolean", "break", "byte", "case", "catch", "char",
                                 "class", "const", "continue", "default", "do", "double", "else", "enum",
                                 "extends", "final", "finally", "float", "for", "goto", "if", "int", "interface",
                                 "long", "new", "private", "protected", "public", "return", "short", "static", "string",
                                 "switch", "this", "throw", "try", "void", "while", "false", "true"};

static const int KEYWORDS_COUNT = sizeof(KEYWORDS) / sizeof(*KEYWORDS);
#endif //SYSPROG_KEYWORDS_H
