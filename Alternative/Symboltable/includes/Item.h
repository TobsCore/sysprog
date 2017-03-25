/*
 * Item.h
 *
 *  Created on: 08.05.2015
 *      Author: holger
 */

#ifndef ITEM_H_
#define ITEM_H_


/*
 * Struktur von einem Listenelement
 */
struct Item{
	Information infoContainer;
	const char* lexem;
	Item* next;
};


#endif /* ITEM_H_ */
