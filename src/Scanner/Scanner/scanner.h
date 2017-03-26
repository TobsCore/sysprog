#ifndef TOKEN
#define TOKEN
#include "../../Token/token.h"
#endif

#ifndef SYMTYPE
#define SYMTYPE
#include "../../SymbolType/symboltype.h"
#endif

#ifndef BUFFER
#define BUFFER
#include "../Buffer/Buffer.h"
#endif

#ifndef AUTOMAT
#define AUTOMAT
#include "../Automat/automat.h"
#endif

class Scanner {

public:
	Scanner(char* filePath);
	~Scanner();

	Token nextToken();


private:
	Buffer* buffer;
	Automat* automat;
};
