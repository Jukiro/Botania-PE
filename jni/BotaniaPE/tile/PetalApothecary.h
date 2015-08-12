#pragma once
#include "BotaniaTile.h"
#include "mcpe/entity/player/Player.h"
//#include "mcpe/level"

class PetalApothecary : public BotaniaTile {
public:
	PetalApothecary(int id) : BotaniaTile(id, &Material::stone) {
		setNameId("petalApothecary");
		setSoundType(Tile::SOUND_STONE);
		destroyTime = 2.0;
	}
	
	int getResource(int i, Random* random){
		return id;
	}
	
	int getResourceCount(Random* random){
		return 1;
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1){
		if(t1==0)
			return getTextureUVCoordinateSet("cobblestone",0);
		if(t1==1)
			return getTextureUVCoordinateSet("cobblestone",0);
		if(t1==2)
			return getTextureUVCoordinateSet("cobblestone",0);
	}
	
	bool isObstructingChests(TileSource* ts, int i1, int i2, int i3){
		return false;
	}
	
	bool isPathfindable(TileSource* ts, int i1, int i2, int i3){
		return false;
	}
	
	bool use(Player* p, int x, int y, int z){
		return true;
	}
};
