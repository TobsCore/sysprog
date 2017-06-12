//
// Created by Kevin Wolf und Tobias Kerst on 08.06.17.
//

enum NodeType {
    INT_TYPE,
    INT_ARRAY_TYPE,
    ARRAY_TYPE,
    NO_TYPE,
    ERROR_TYPE,
    OP_PLUS_TYPE,
    OP_MINUS_TYPE,
    OP_MULT_TYPE,
    OP_DIV_TYPE,
    OP_LESS_TYPE,
    OP_GREATER_TYPE,
    OP_EQUAL_TYPE,
    OP_UN_EQUAL_TYPE,
    OP_AND_TYPE
};

inline const char *toString(NodeType type) {
    switch (type) {
        case INT_TYPE:
            return "INT_TYPE";
        case INT_ARRAY_TYPE:
            return "INT_ARRAY_TYPE";
        case ARRAY_TYPE:
            return "ARRAY_TYPE";
        case NO_TYPE:
            return "NO_TYPE";
        case ERROR_TYPE:
            return "ERROR_TYPE";
        case OP_PLUS_TYPE:
            return "OP_PLUS_TYPE";
        case OP_MINUS_TYPE:
            return "OP_MINUS_TYPE";
        case OP_MULT_TYPE:
            return "OP_MULT_TYPE";
        case OP_DIV_TYPE:
            return "OP_DIV_TYPE";
        case OP_LESS_TYPE :
            return "OP_LESS_TYPE";
        case OP_GREATER_TYPE:
            return "OP_GREATER_TYPE";
        case OP_EQUAL_TYPE:
            return "OP_EQUAL_TYPE";
        case OP_UN_EQUAL_TYPE :
            return "OP_UN_EQUAL_TYPE";
        case OP_AND_TYPE :
            return "OP_AND_TYPE";
        default:
            return "Unknown Type";
    }
};
