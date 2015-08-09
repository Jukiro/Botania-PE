#pragma once

#include "BotaniaTile.h"

class Livingwood : public BotaniaTile {
public:
	Livingwood(int id) : BotaniaTile(id, "livingwood", &Material::stone) {
		setNameId("livingwood");
		setSoundType(Tile::SOUND_STONE); //yes it is supposed to be like stone.
	}
	
	int getResource(int i, Random* random){
		return id;
	}
	int getResourceCount(Random* random){
		return 1;
	}
};
