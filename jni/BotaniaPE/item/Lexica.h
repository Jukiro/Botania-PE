#pragma once

#include "BotaniaItem.h"

class Lexica : public BotaniaItem {
public:
	Lexica(int id) : BotaniaItem(id) {
		setNameID("lexicaBotania");
		setIcon("lexicon",0);
	}
};
