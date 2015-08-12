#pragma once

#include "BotaniaFlower.h"

class PureDaisy : public BotaniaFlower {
public:
	PureDaisy(int id) : BotaniaFlower(id) {
		setNameId("pureDaisy");
		tex = getTextureUVCoordinateSet("puredaisy", 0);
		destroyTime = 0.0;
		canInstaTick = true;
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1) {
		switch(t1){
		case 0:
			return getTextureUVCoordinateSet("puredaisy", 0);
			break;
		default:
			return getTextureUVCoordinateSet("puredaisy", 0);
			break;
		}
	}
	
	void purify(TileSource* ts, int x, int y, int z){
		Tile* tile = ts->getTilePtr(x,y,z);
		int setId;
		switch(tile->id){
			case 1:
				setId = 202;
				break;
			case 17:
				setId = 203;
				break;
			case 87:
				setId = 4;
				break;
			case 88: //only in 0.12 and up - SoulSand
				setId = 12;
				break;
			case 79: //again only useful in 0.12 with silk touch
				setId = 174;
				break;
			case 9:
				setId = 80;
				break;
		}
		ts->setTileAndData(x,y,z,{setId,0}, 3);
	}
	
	void tick(TileSource* ts, int x, int y, int z, Random* random){
		//these "purifications" need to happen after 1 minute 20 seconds (1600 ticks)
		purify(ts, x+1, y, z);
		purify(ts, x-1, y, z);
		purify(ts, x, y, z+1);
		purify(ts, x, y, z-1);
		purify(ts, x+1, y, z+1);
		purify(ts, x-1, y, z-1);
		purify(ts, x+1, y, z-1);
		purify(ts, x-1, y, z+1);
	}
};
