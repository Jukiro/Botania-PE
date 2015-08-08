#pragma once

#include "BotaniaFlower.h"

class PureDaisy : public BotaniaFlower {
public:
	PureDaisy(int id) : BotaniaFlower(id) {
		setNameId("pureDaisy");
		tex = getTextureUVCoordinateSet("puredaisy", 0);
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1) {
		if(t1==0) return getTextureUVCoordinateSet("puredaisy", 0);
	}
};
