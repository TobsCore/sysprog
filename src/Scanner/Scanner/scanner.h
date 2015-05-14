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

#ifndef SCANNER
#define SCANNER
#include "scanner.h"
#endif

class Scanner {

public:
	int getCurrentRow();
	int getCurrentColumn();

	void setCurrentRow(int row);
	void setCurrentColumn(int col);


private:
	int myrow;
	int mycolumn;
	Buffer buffer;
	Automat automat;
	Token token;
};
