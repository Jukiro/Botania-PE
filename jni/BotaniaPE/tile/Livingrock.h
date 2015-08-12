#pragma once

#include "BotaniaTile.h"

class Livingrock : public BotaniaTile {
public:
	Livingrock(int id) : BotaniaTile(id, "livingrock", &Material::stone) {
		setNameId("livingrock");
		setSoundType(Tile::SOUND_STONE);
		destroyTime = 2.0;
	}
	
	int getResource(int i, Random* random){
		return id;
	}
	
	int getResourceCount(Random* random){
		return 1;
	}
};
