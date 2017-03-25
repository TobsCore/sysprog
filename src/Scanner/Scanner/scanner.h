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
	Scanner(char* filePath);
	~Scanner();
	int getCurrentRow();
	int getCurrentColumn();

	void setCurrentRow(int row);
	void setCurrentColumn(int col);

	Token nextToken();


private:
	int currentRow;
	int currentColumn;
	Buffer* buffer;
	Automat* automat;
};
