namespace sign
{
    enum signtype
    {
        ERROR = -1,             // If error occurs
        NEXTCHAR = 0,           // Expects the next char
        INTEGER = 1,            // Integer
        IDENTIFIER = 2,         // should explain itself
    	PLUS = 3,				// +
		MINUS = 4,				// -
		COLON = 5,				// :
		STAR = 6,				// *
		LESS = 7, 				// <
		GREATER = 8, 			// >
		EQUALS = 9,				// =
		ASSIGN = 10,		 	// :=
		SPECIAL = 11, 			// <:>
		EXCLAMATION = 12,		// !
		AND = 13,				// &
		SEMICOLON = 14,			// ;
		PARANTHESES_LEFT = 15, 	// (
		PARANTHESES_RIGHT = 16, // )
		BRACES_LEFT  = 17, 		// {
		BRACES_RIGHT = 18, 		// }
		BRACKET_LEFT = 19, 		// [
		BRACKET_RIGHT = 20 		// ]
    };
}
