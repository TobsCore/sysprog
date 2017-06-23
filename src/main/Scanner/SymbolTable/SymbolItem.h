/*
 * SymbolItem.h
 *
 *  Created on: 08.05.2015
 *      Author: holger
 */

#include "../../Parser/Parser/NodeType.h"

#ifndef SYMBOLITEM_H_
#define SYMBOLITEM_H_

/*
 * Struktur von einem Listenelement
 */
struct SymbolItem {
    SymbolItem() {}

    const char *lexem;
    SymbolItem *next;
    NodeType nodeType = NO_TYPE;
};


#endif /* ITEM_H_ */
