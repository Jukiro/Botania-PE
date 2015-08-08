#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/ItemInstance.h"

class PetalItem : public Item {
public:
	static PetalItem* petalItem;
	
	virtual std::string getName(const ItemInstance *) const;
	//virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	
	PetalItem(int);
};
