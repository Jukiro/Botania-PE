#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/ItemInstance.h"

class BotaniaItem : public Item {
public:
	BotaniaItem(int id) : Item(id - 0x100){
		setStackedByData(true); //I dont see a reason not to have this
	}
};
