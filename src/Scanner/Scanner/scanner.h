#ifndef token
#define token
#include "../../Token/token.h"
#endif

#ifndef symtype
#define symtype
#include "../../SymbolType/symboltype.h"
#endif

#ifndef buffer
#define buffer
#include "../Buffer/Buffer.h"
#endif

#ifndef automat
#define automat
#include "../Automat/automat.h"
#endif

#ifndef scanner
#define scanner
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
