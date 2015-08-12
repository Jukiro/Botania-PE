#pragma once

#include "BotaniaItem.h"

class BotaniaTool : public BotaniaItem {
public:
	BotaniaTool(int id) : BotaniaItem(id) {
		setMaxStackSize(1);
		setIcon("manasteelPick",0);
		setNameID("manasteelPick");
		setMaxDamage(500);
	}
	
	float getDestroySpeed(ItemInstance* inst, Tile* tile){
		if(inst->getId() == 502){
			if(tile->id == 1){
				return 4.0;
			}
			else{
				return 1.0;
			}
		}
	}
	
};
