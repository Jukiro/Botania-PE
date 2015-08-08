#pragma once

#include "BotaniaFlower.h"

class MysticalFlower : public BotaniaFlower {
public:
	MysticalFlower(int id) : BotaniaFlower(id) {
		setNameId("mysticalFlower");
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1) {
		return getTextureUVCoordinateSet("flower", 0);
	}
};
