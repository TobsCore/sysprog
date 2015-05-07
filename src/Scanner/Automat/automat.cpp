// Der Automat merkt sich, in welchem Zustand er ist.
// Gibt Integer Werte zurück, die jeweils für die entsprechenden Typen des Tokens stehen.

// Aus schlüsselwörtern wie "if" und "while" werden Identifier gemacht

/** Es wird ein int zurückgegeben, dass durch ein enum eine schöne Beschreibung bekommt
 	* -1 > baue ein FehlerToken
 	* 0 > noch ein char, bitte!
 	* 1 > baue ein IntegerToken
 	* 2 > baue ein IdentifierToken
 	* 3 > baue ein PlusToken
 	* 4 > baue ein MinusToken
 	* etc.
*/

#include <symboltype.h>
using namespace sign;

class Automat {

	private:
		int currentState;
		int newState;
		int column;

		typedef struct {
			int nextState;
			int returnValue;
		}  stateElement;

		stateElement stateMatrix[5][4] = {
				//digit	//letter  //+	 //leer
			   { {1,0},  {2,0},  {3,0},  {0,0}   },  // s0
			   { {1,0},  {-1,0}, {3,1},  {0,1}   },  // s1
			   { {2,0},  {2,0},  {3,2},  {0,2}   },	// s2
			   { {1,3},  {2,3},  {3,3},  {0,3}   },	// s3
			   { {-1,0}, {-1,0}, {3,-1}, {0,-1}  },	// s-1
		};

		int findColumn (char currentChar) {
					if ((int)currentChar > 47 && (int)currentChar < 58) {
							//digit
							return 0;
						} else if (((int)currentChar > 64 && (int)currentChar < 91) // uppercase Letter
								|| ((int)currentChar > 96 && (int)currentChar < 123)) // lowercase Letter
							{
							// Letter
							return 1;
						} else {
							switch (currentChar) {
								case '+': return 2;
								case '-': return 3;
								case ':': return 4;
								case '*': return 5;
								case '<': return 6;
								case '>': return 7;
								case '=': return 8;
								case '!': return 9;
								case '&': return 10;
								case ';': return 11;
								case '(': return 12;
								case ')': return 13;
								case '{': return 14;
								case '}': return 15;
								case '[': return 16;
								case ']': return 17;
								default: return 18;
							}
						}
				}

	public:
		Automat(){
			this->currentState = 0;
			this->newState = 0;
			this->column = 0;
		}

		int checkExpression(char currentChar){
			this->currentState = this->newState;
			column = findColumn(currentChar);
			this->newState = stateMatrix[this->currentState][column].nextState;

			return stateMatrix[this->currentState][column].returnValue;
		}
};
