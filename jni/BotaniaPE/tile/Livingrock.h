#pragma once

#include "BotaniaTile.h"

class Livingrock : public BotaniaTile {
public:
	Livingrock(int id) : BotaniaTile(id, "livingrock", &Material::stone) {
		setNameId("livingrock");
		setSoundType(Tile::SOUND_STONE);
	}
	
	int getResource(int i, Random* random){
		return id;
	}
	
	int getResourceCount(Random* random){
		return 1;
	}
};
