namespace sign
{
    enum Signtype
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
		EXCLAMATION = 10,		// !
		AND = 11,				// &
		SEMICOLON = 12,			// ;
		PARANTHESES_LEFT = 13, 	// (
		PARANTHESES_RIGHT = 14, // )
		BRACES_LEFT  = 15, 		// {
		BRACES_RIGHT = 16, 		// }
		BRACKET_LEFT = 17, 		// [
		BRACKET_RIGHT = 18, 		// ]
		ASSIGN = 19,		 	// :=
		SPECIAL = 20 			// <:>
    };
}
