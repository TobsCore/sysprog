/*
 * SymbolItem.h
 *
 *  Created on: 08.05.2015
 *      Author: holger
 */

#ifndef INFOMATION
#define INFOMATION

#include "Information.h"

#endif

#ifndef SYMBOLITEM_H_
#define SYMBOLITEM_H_

/*
 * Struktur von einem Listenelement
 */
struct SymbolItem {
    SymbolItem() {}

    Information infoContainer;
    const char *lexem;
    SymbolItem *next;
};


#endif /* ITEM_H_ */
