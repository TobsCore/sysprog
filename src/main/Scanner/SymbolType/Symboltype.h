#ifndef SYMBOLTYPE
#define SYMBOLTYPE

enum SymbolType {

    ERROR = -1,             // If error occurs
    NEXTCHAR = 0,           // Expects the next char
    INTEGER = 1,            // Integer
    IDENTIFIER = 2,         // should explain itself
    PLUS = 3,                // +
    MINUS = 4,                // -
    COLON = 5,                // :
    STAR = 6,                // *
    LESS = 7,                // <
    GREATER = 8,            // >
    EQUALS = 9,                // =
    EXCLAMATION = 10,        // !
    AND = 11,                // &&
    SEMICOLON = 12,            // ;
    PARANTHESES_LEFT = 13,    // (
    PARANTHESES_RIGHT = 14, // )
    BRACES_LEFT = 15,        // {
    BRACES_RIGHT = 16,        // }
    BRACKET_LEFT = 17,        // [
    BRACKET_RIGHT = 18,    // ]
    ASSIGN = 19,            // :=
    SPECIAL = 20,            // =:=
    COMMENT = 21,            // Comment
    ERROR_SPECIAL = 22,        // Expected a special sign, but wasn't.
    IN_COMMENT = 23,        // Beginning of Comment
    IFTOKEN = 24,
    WHILETOKEN = 25,
    WRITETOKEN = 26,
    READTOKEN = 27,
    ELSETOKEN = 28,
    INTTOKEN = 29,
    FILE_END = 50            // End of file
};

static const char *EnumStrings[] = {"EOF", "Error", "Nextchar", "Integer", "Identifier", "Plus", "Minus", "Colon",
                                    "Star", "Less", "Greater", "Equals",
                                    "Exclamation", "And", "Semicolon", "Parenthesis (open)", "Parenthesis (close)",
                                    "Brace (open)", "Brace (close)", "Bracket (open)", "Bracket (close)",
                                    "Assign", "Special", "Comment", "Error Special", "In Comment", "If", "While", "Write", "Read", "Else", "int"}; //kp

#endif

