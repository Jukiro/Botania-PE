#pragma once

#include "FlowerTile.h"

class MysticalFlower : public FlowerTile {
public:
	virtual TextureUVCoordinateSet const& getTexture(signed char, int);
	virtual std::string getName(const ItemInstance *) const;
	
	MysticalFlower(int, Material const*);
};
