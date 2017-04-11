/*
 * Information.cpp
 *
 *  Created on: 03.05.2015
 *      Author: holger
 */

#include <iostream>
#include <cstdlib>

#include "Information.h"
#include "../SymbolType/Symboltype.h"


using namespace std;

	Information::Information(){
		this->type = IDENTIFIER;
		this->name = NULL;
		this->keyword = NOKEYWORD;
	}

	Information::Information(SymbolType type, const char* name){
		this->type = IDENTIFIER;
		this->name = name;
		this->keyword = this->isKeyword();
	}
	const char* Information::getName(){
		return this->name;
	}
	void Information::setName(const char* name2){
		this->name = name2;
		if(this->name != NULL && this->type != 0){
			this->keyword = this->isKeyword();
		}
	}
	SymbolType Information::getType(){
		return this->type;
	}
	void Information::setType(SymbolType type2){
		this->type = type2;
		if(this->name != NULL && this->type != 0){
			this->keyword = this->isKeyword();
		}
	}
	Keyword Information::getKeyword(){
		return this->keyword;
	}
	void Information::setKeyword(Keyword keyword2){
		this->keyword = keyword2;
	}
	int Information::nameLength(){
		int i = 0;
			while(this->name[i] != '\0'){
				i++;
			}
		return i;
	}
	Keyword Information::isKeyword(){

		/*
		switch(this->name) {
			case "if":
				return IF;

		}
		*/


		if(this->type == IDENTIFIER){
			int length = this->nameLength();
			int i = 0;
			if(length == 2){
				char ifType[] = "if";
				while(this->name[i] != '\0'){
					if(this->name[i] != ifType[i]){
						return NOKEYWORD;
					}
					i++;
				}
				return IF;
			} else if(length == 5){
				char whileType[] = "while";
				while(this->name[i] != '\0'){
					if(this->name[i] != whileType[i]){
						return NOKEYWORD;
					}
					i++;
				}
				return WHILE;
			}
		}
		return NOKEYWORD;
	}


	void Information::viewInformation(){
		cout	<< "----------------------------\n"
				<< "Type: " << type << endl
				<< "Keyword: " << keyword << endl
				<< "Name: " << name << endl
				<< "----------------------------" << endl;
	}
/*Information& Information::operator=(Information& infoGleich){
	this->type = infoGleich.type;
	this->name = infoGleich.name;
	this->keyword = infoGleich.keyword;
	return infoGleich;
}
bool Information::operator==(Information& infoVergleich){
	if(this->type == infoVergleich.type
		&& strcmp(this->name, infoVergleich.name) == 0){
			return true;
	}
	return false;
}*/
Information::~Information(){
}
