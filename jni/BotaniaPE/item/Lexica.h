#pragma once

#include "BotaniaItem.h"

class Lexica : public BotaniaItem {
public:
	Lexica(int id) : BotaniaItem(id - 0x100) {
		setNameID("lexicaBotania");
		setIcon("lexicon",0);
	}
};
