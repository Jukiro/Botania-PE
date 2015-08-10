#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/ItemInstance.h"

class BotaniaItem : public Item {
public:
	BotaniaItem(int id) : Item(id){
		setStackedByData(true); //I dont see a reason not to have this
	}
};
