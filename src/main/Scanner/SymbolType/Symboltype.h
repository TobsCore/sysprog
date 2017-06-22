#ifndef SYMBOLTYPE
#define SYMBOLTYPE

#include <exception>
#include <stdexcept>

enum SymbolType {

    NOT_SET = -2,
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


inline const char* ToString(SymbolType type) {
    switch (type) {
        case NOT_SET:
            return "Not Set";
        case ERROR:
            return "Error";
        case NEXTCHAR:
            return "Nextchar";
        case INTEGER:
            return "Integer";
        case IDENTIFIER:
            return "Identifier";
        case PLUS:
            return "Plus";
        case MINUS:
            return "Minus";
        case COLON:
            return "Colon";
        case STAR:
            return "Star";
        case LESS:
            return "Less";
        case GREATER:
            return "Greater";
        case EQUALS:
            return "Equals";
        case EXCLAMATION:
            return "Exclamation";
        case AND:
            return "And";
        case SEMICOLON:
            return "Semicolon";
        case PARANTHESES_LEFT:
            return "Parens (left)";
        case PARANTHESES_RIGHT:
            return "Parens (right)";
        case BRACES_LEFT:
            return "Braces (left)";
        case BRACES_RIGHT:
            return "Braces (right)";
        case BRACKET_LEFT:
            return "Brackets (left)";
        case BRACKET_RIGHT:
            return "Brackets (right)";
        case ASSIGN:
            return "Assign";
        case SPECIAL:
            return "Sprecial";
        case COMMENT:
            return "Comment";
        case ERROR_SPECIAL:
            return "Error in Special";
        case IN_COMMENT:
            return "In Comment";
        case IFTOKEN:
            return "If";
        case WHILETOKEN:
            return "While";
        case READTOKEN:
            return "Read";
        case WRITETOKEN:
            return "Write";
        case ELSETOKEN:
            return "Else";
        case INTTOKEN:
            return "Int";
        case FILE_END:
            return "File End";
        default:
            throw std::invalid_argument("Unknown Type");

    }
};

#endif

