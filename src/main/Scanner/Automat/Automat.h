#ifndef SYMTYPE
#define SYMTYPE
#include "../../SymbolType/Symboltype.h"
#endif

class Automat {

public:
	Automat();
	SymbolType checkExpression(char currentChar);

private:
	int findColumn(char currentChar);

	int currentState;
	int newState;
	int column;

	typedef struct {
		int nextState;
		SymbolType returnValue;
	} stateElement;

	/* Funktionsweise:
	 *
	 * Die Spalten stehen für die Zeichen, die gerade getestet werden. Wurde beispielsweise ein "!" (ohhne "") eingelesen, so wird für den aktuellen Zustand geprüft, in welchen Folgezustand
	 * man geht und welches Zeichen ausgegeben wird. Die Zustände stehen als Kommentar in den Zeilen (ganz rechts). Die Wertepaare in der Matrix stehen für den Folgezustand und den zurückgegebenen Typen.
	 * Der zurückgegebene Typ bestimmt dann also für das nächste Zeichen, in welche Zeile man gucken muss.
	 */

	stateElement stateMatrix[27][20] = {
			//digit					 //letter  				 //+	   				 //-    				 //: 	  				 //*     				 //<     				 //>     				 //=     				 //!      				 //&      				 //;      				 //(  	 				 //)	   				 //{    	 			 //}  	 				 //[ 	  				 //]      				 //leer
		   { {1,NEXTCHAR},  		{2,NEXTCHAR},   		{3,NEXTCHAR},  			{4,NEXTCHAR},  			{5,NEXTCHAR},  			{6,NEXTCHAR},  			{7,NEXTCHAR},  			{8,NEXTCHAR},  			{9,NEXTCHAR},  			{10,NEXTCHAR},  		{11,NEXTCHAR},  		{12,NEXTCHAR},  		{13,NEXTCHAR},  		{14,NEXTCHAR},  		{15,NEXTCHAR},  		{16,NEXTCHAR},  		{17,NEXTCHAR},  		{18,NEXTCHAR},  		{0,NEXTCHAR}   }, // s0
		   { {1,NEXTCHAR},  		{19,NEXTCHAR},  		{3,INTEGER},  			{4,INTEGER},  			{5,INTEGER},  			{6,INTEGER},  			{7,INTEGER},  			{8,INTEGER},  			{9,INTEGER},  			{10,INTEGER},  			{11,INTEGER},  			{12,INTEGER},  			{13,INTEGER},  			{14,INTEGER},  			{15,INTEGER},  			{16,INTEGER},  			{17,INTEGER},  			{18,INTEGER},  			{0,INTEGER}   }, // s1
		   { {2,NEXTCHAR},  		{2,NEXTCHAR},   		{3,IDENTIFIER},  		{4,IDENTIFIER},  		{5,IDENTIFIER},  		{6,IDENTIFIER},  		{7,IDENTIFIER},  		{8,IDENTIFIER},  		{9,IDENTIFIER},  		{10,IDENTIFIER},  		{11,IDENTIFIER},  		{12,IDENTIFIER},  		{13,IDENTIFIER},  		{14,IDENTIFIER},  		{15,IDENTIFIER},  		{16,IDENTIFIER},  		{17,IDENTIFIER},  		{18,IDENTIFIER},  		{0,IDENTIFIER}   }, // s2
		   { {1,PLUS},  			{2,PLUS},   			{3,PLUS},  				{4,PLUS},  				{5,PLUS},  				{6,PLUS},  				{7,PLUS},  				{8,PLUS},  				{9,PLUS},  				{10,PLUS},  			{11,PLUS},  			{12,PLUS},  			{13,PLUS},  			{14,PLUS},  			{15,PLUS},  			{16,PLUS},  			{17,PLUS},  			{18,PLUS},  			{0,PLUS}   }, // s3
		   { {1,MINUS},  			{2,MINUS},   			{3,MINUS},  			{4,MINUS},  			{5,MINUS},  			{6,MINUS},  			{7,MINUS},  			{8,MINUS},  			{9,MINUS},  			{10,MINUS},  			{11,MINUS},  			{12,MINUS},  			{13,MINUS},  			{14,MINUS},  			{15,MINUS},  			{16,MINUS},  			{17,MINUS},  			{18,MINUS},  			{0,MINUS}   }, // s4
		   { {1,COLON},  			{2,COLON},   			{3,COLON},  			{4,COLON},  			{5,COLON},  			{24,NEXTCHAR},  		{7,COLON},  			{8,COLON},  			{19,NEXTCHAR}, 			{10,COLON},  			{11,COLON},  			{12,COLON},  			{13,COLON},  			{14,COLON},  			{15,COLON},  			{16,COLON},  			{17,COLON},  			{18,COLON},  			{0,COLON}   }, // s5
		   { {1,STAR},  			{2,STAR},   			{3,STAR},  				{4,STAR},  				{5,STAR},  				{6,STAR},  				{7,STAR},  				{8,STAR},  				{9,STAR},  				{10,STAR},  			{11,STAR},  			{12,STAR},  			{13,STAR},  			{14,STAR},  			{15,STAR},  			{16,STAR},  			{17,STAR},  			{18,STAR},  			{0,STAR}   }, // s6
		   { {1,LESS},  			{2,LESS},   			{3,LESS},  				{4,LESS},  				{5,LESS},  				{6,LESS},  				{7,LESS},  				{8,LESS},  				{9,LESS},  				{10,LESS},  			{11,LESS},  			{12,LESS},  			{13,LESS},  			{14,LESS},  			{15,LESS},  			{16,LESS},  			{17,LESS},  			{18,LESS},  			{0,LESS}   }, // s7
		   { {1,GREATER},  			{2,GREATER},   			{3,GREATER},  			{4,GREATER},  			{5,GREATER},  			{6,GREATER},  			{7,GREATER},  			{8,GREATER},  			{9,GREATER},  			{10,GREATER},  			{11,GREATER},  			{12,GREATER},  			{13,GREATER},  			{14,GREATER},  			{15,GREATER},  			{16,GREATER},  			{17,GREATER},  			{18,GREATER},  			{0,GREATER}   }, // s8
		   { {1,EQUALS},  			{2,EQUALS},   			{3,EQUALS},  			{4,EQUALS},  			{21,NEXTCHAR}, 			{6,EQUALS},  			{7,EQUALS},  			{8,EQUALS},  			{9,EQUALS},  			{10,EQUALS},  			{11,EQUALS},  			{12,EQUALS},  			{13,EQUALS},  			{14,EQUALS},  			{15,EQUALS},  			{16,EQUALS},  			{17,EQUALS},  			{18,EQUALS},  			{0,EQUALS}   }, // s9
		   { {1,EXCLAMATION}, 		{2,EXCLAMATION},  		{3,EXCLAMATION}, 		{4,EXCLAMATION}, 		{5,EXCLAMATION}, 		{6,EXCLAMATION}, 		{7,EXCLAMATION}, 		{8,EXCLAMATION}, 		{9,EXCLAMATION}, 		{10,EXCLAMATION}, 		{11,EXCLAMATION}, 		{12,EXCLAMATION}, 		{13,EXCLAMATION}, 		{14,EXCLAMATION}, 		{15,EXCLAMATION}, 		{16,EXCLAMATION}, 		{17,EXCLAMATION}, 		{18,EXCLAMATION}, 		{0,EXCLAMATION}  }, // s10
		   { {1,ERROR}, 			{2,ERROR},  			{3,ERROR}, 				{4,ERROR}, 				{5,ERROR}, 				{6,ERROR}, 				{7,ERROR}, 				{8,ERROR}, 				{9,ERROR}, 				{10,ERROR}, 			{20,NEXTCHAR},  		{12,ERROR}, 			{13,ERROR}, 			{14,ERROR}, 			{15,ERROR}, 			{16,ERROR}, 			{17,ERROR}, 			{18,ERROR}, 			{0,NEXTCHAR}   }, // s11-intermediate
		   { {1,SEMICOLON}, 		{2,SEMICOLON},  		{3,SEMICOLON}, 			{4,SEMICOLON}, 			{5,SEMICOLON}, 			{6,SEMICOLON}, 			{7,SEMICOLON}, 			{8,SEMICOLON}, 			{9,SEMICOLON}, 			{10,SEMICOLON}, 		{11,SEMICOLON}, 		{12,SEMICOLON}, 		{13,SEMICOLON}, 		{14,SEMICOLON}, 		{15,SEMICOLON}, 		{16,SEMICOLON}, 		{17,SEMICOLON}, 		{18,SEMICOLON}, 		{0,SEMICOLON}  }, // s12
		   { {1,PARANTHESES_LEFT}, 	{2,PARANTHESES_LEFT},  	{3,PARANTHESES_LEFT}, 	{4,PARANTHESES_LEFT}, 	{5,PARANTHESES_LEFT}, 	{6,PARANTHESES_LEFT}, 	{7,PARANTHESES_LEFT}, 	{8,PARANTHESES_LEFT}, 	{9,PARANTHESES_LEFT}, 	{10,PARANTHESES_LEFT}, 	{11,PARANTHESES_LEFT}, 	{12,PARANTHESES_LEFT}, 	{13,PARANTHESES_LEFT}, 	{14,PARANTHESES_LEFT}, 	{15,PARANTHESES_LEFT}, 	{16,PARANTHESES_LEFT}, 	{17,PARANTHESES_LEFT}, 	{18,PARANTHESES_LEFT}, 	{0,PARANTHESES_LEFT}  }, // s13
		   { {1,PARANTHESES_RIGHT}, {2,PARANTHESES_RIGHT}, 	{3,PARANTHESES_RIGHT}, 	{4,PARANTHESES_RIGHT}, 	{5,PARANTHESES_RIGHT}, 	{6,PARANTHESES_RIGHT}, 	{7,PARANTHESES_RIGHT}, 	{8,PARANTHESES_RIGHT}, 	{9,PARANTHESES_RIGHT}, 	{10,PARANTHESES_RIGHT}, {11,PARANTHESES_RIGHT}, {12,PARANTHESES_RIGHT}, {13,PARANTHESES_RIGHT}, {14,PARANTHESES_RIGHT}, {15,PARANTHESES_RIGHT}, {16,PARANTHESES_RIGHT}, {17,PARANTHESES_RIGHT}, {18,PARANTHESES_RIGHT}, {0,PARANTHESES_RIGHT}  }, // s14
		   { {1,BRACES_LEFT}, 		{2,BRACES_LEFT},  		{3,BRACES_LEFT}, 		{4,BRACES_LEFT}, 		{5,BRACES_LEFT}, 		{6,BRACES_LEFT}, 		{7,BRACES_LEFT}, 		{8,BRACES_LEFT}, 		{9,BRACES_LEFT}, 		{10,BRACES_LEFT}, 		{11,BRACES_LEFT}, 		{12,BRACES_LEFT}, 		{13,BRACES_LEFT}, 		{14,BRACES_LEFT}, 		{15,BRACES_LEFT}, 		{16,BRACES_LEFT}, 		{17,BRACES_LEFT}, 		{18,BRACES_LEFT}, 		{0,BRACES_LEFT}  }, // s15
		   { {1,BRACES_RIGHT}, 		{2,BRACES_RIGHT},  		{3,BRACES_RIGHT}, 		{4,BRACES_RIGHT}, 		{5,BRACES_RIGHT}, 		{6,BRACES_RIGHT}, 		{7,BRACES_RIGHT}, 		{8,BRACES_RIGHT}, 		{9,BRACES_RIGHT}, 		{10,BRACES_RIGHT}, 		{11,BRACES_RIGHT}, 		{12,BRACES_RIGHT}, 		{13,BRACES_RIGHT}, 		{14,BRACES_RIGHT}, 		{15,BRACES_RIGHT}, 		{16,BRACES_RIGHT}, 		{17,BRACES_RIGHT}, 		{18,BRACES_RIGHT}, 		{0,BRACES_RIGHT}  }, // s16
		   { {1,BRACKET_LEFT}, 		{2,BRACKET_LEFT},  		{3,BRACKET_LEFT}, 		{4,BRACKET_LEFT}, 		{5,BRACKET_LEFT}, 		{6,BRACKET_LEFT}, 		{7,BRACKET_LEFT}, 		{8,BRACKET_LEFT}, 		{9,BRACKET_LEFT}, 		{10,BRACKET_LEFT}, 		{11,BRACKET_LEFT}, 		{12,BRACKET_LEFT}, 		{13,BRACKET_LEFT}, 		{14,BRACKET_LEFT}, 		{15,BRACKET_LEFT}, 		{16,BRACKET_LEFT}, 		{17,BRACKET_LEFT}, 		{18,BRACKET_LEFT}, 		{0,BRACKET_LEFT}  }, // s17
		   { {1,BRACKET_RIGHT},		{2,BRACKET_RIGHT},  	{3,BRACKET_RIGHT}, 		{4,BRACKET_RIGHT}, 		{5,BRACKET_RIGHT}, 		{6,BRACKET_RIGHT}, 		{7,BRACKET_RIGHT}, 		{8,BRACKET_RIGHT}, 		{9,BRACKET_RIGHT}, 		{10,BRACKET_RIGHT}, 	{11,BRACKET_RIGHT}, 	{12,BRACKET_RIGHT}, 	{13,BRACKET_RIGHT}, 	{14,BRACKET_RIGHT}, 	{15,BRACKET_RIGHT}, 	{16,BRACKET_RIGHT}, 	{17,BRACKET_RIGHT}, 	{18,BRACKET_RIGHT}, 	{0,BRACKET_RIGHT}  }, // s18
		   { {1,ASSIGN}, 			{2,ASSIGN},  			{3,ASSIGN}, 			{4,ASSIGN}, 			{5,ASSIGN}, 			{6,ASSIGN}, 			{7,ASSIGN}, 			{8,ASSIGN}, 			{9,ASSIGN}, 			{10,ASSIGN}, 			{11,ASSIGN}, 			{12,ASSIGN}, 			{13,ASSIGN}, 			{14,ASSIGN}, 			{15,ASSIGN}, 			{16,ASSIGN}, 			{17,ASSIGN}, 			{18,ASSIGN}, 			{0,ASSIGN}  }, // s19
		   { {1,AND}, 				{2,AND},  				{3,AND}, 				{4,AND}, 				{5,AND}, 				{6,AND}, 				{7,AND}, 				{8,AND}, 				{9,AND}, 				{10,AND}, 				{11,AND}, 				{12,AND}, 				{13,AND}, 				{14,AND}, 				{15,AND}, 				{16,AND}, 				{17,AND}, 				{18,AND}, 				{0,AND}  }, // s11
		   { {5,ERROR_SPECIAL}, 	{5,ERROR_SPECIAL},  	{5,ERROR_SPECIAL}, 		{5,ERROR_SPECIAL}, 		{5,ERROR_SPECIAL},	    {5,ERROR_SPECIAL}, 		{5,ERROR_SPECIAL}, 		{5,ERROR_SPECIAL}, 		{22,NEXTCHAR}, 			{5,ERROR_SPECIAL},		{5,ERROR_SPECIAL}, 	    {5,ERROR_SPECIAL},  	{5,ERROR_SPECIAL}, 	    {5,ERROR_SPECIAL}, 	    {5,ERROR_SPECIAL}, 	    {5,ERROR_SPECIAL},      {5,ERROR_SPECIAL},  	{5,ERROR_SPECIAL},  	{0,ERROR_SPECIAL}  }, // s20-intermediate
		   { {1,SPECIAL}, 			{2,SPECIAL},  			{3,SPECIAL}, 			{4,SPECIAL}, 			{5,SPECIAL}, 			{6,SPECIAL}, 			{7,SPECIAL}, 			{8,SPECIAL}, 			{9,SPECIAL}, 			{10,SPECIAL}, 			{11,SPECIAL}, 			{12,SPECIAL}, 			{13,SPECIAL}, 			{14,SPECIAL}, 			{15,SPECIAL}, 			{16,SPECIAL}, 			{17,SPECIAL}, 			{18,SPECIAL}, 			{0,SPECIAL}  }, // s20
		   { {19,NEXTCHAR}, 		{19,NEXTCHAR},  		{3,ERROR}, 				{4,ERROR}, 				{5,ERROR}, 				{6,ERROR}, 				{7,ERROR}, 				{8,ERROR}, 				{9,ERROR}, 				{10,ERROR}, 			{11,ERROR}, 			{12,ERROR}, 			{13,ERROR}, 			{14,ERROR}, 			{15,ERROR}, 			{16,ERROR}, 			{17,ERROR}, 			{18,ERROR}, 			{0,ERROR}  },  // s-1
		   { {24,IN_COMMENT}, 	{24,IN_COMMENT},  	{24,IN_COMMENT}, 	{24,IN_COMMENT}, 	{24,IN_COMMENT}, 	{25,IN_COMMENT}, 	{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}, 			{24,IN_COMMENT}  },
		   { {25,IN_COMMENT}, 		{25,IN_COMMENT},  		{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{26,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 			{25,IN_COMMENT}, 	{25,IN_COMMENT}, 	{25,IN_COMMENT}, 	{25,IN_COMMENT}, 	{25,IN_COMMENT}, 	{25,IN_COMMENT}  },
           { {1,COMMENT}, 			{2,COMMENT},  			{3,COMMENT}, 			{4,COMMENT}, 			{5,COMMENT}, 			{6,COMMENT}, 			{7,COMMENT}, 			{8,COMMENT}, 			{9,COMMENT}, 			{10,COMMENT}, 			{11,COMMENT}, 			{12,COMMENT}, 			{13,COMMENT}, 			{14,COMMENT}, 			{15,COMMENT}, 			{16,COMMENT}, 			{17,COMMENT}, 			{18,COMMENT}, 			{0,COMMENT}  }, //
	};
};
