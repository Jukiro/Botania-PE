#pragma once

#include "BotaniaTile.h"

class BotaniaFlower : public BotaniaTile {
public:
	BotaniaFlower(int blockId, std::string tex) : BotaniaTile(blockId, tex, &Material::decoration) {
		setSoundType(Tile::SOUND_GRASS);
		setDestroyTime(0.0);
		setCategory(2);
		renderPass = 3;
	}
	
	BotaniaFlower(int blockId) : BotaniaTile(blockId, &Material::decoration) {
		setSoundType(Tile::SOUND_GRASS);
		setDestroyTime(0.0);
		setCategory(2);
		renderPass = 3;
	}
	
	void neighborChanged(TileSource* ts, int x, int y, int z, int xx, int yy, int zz) {
		if(ts->getTilePtr(x, y - 1, z) == NULL) ts->setTileAndData(x, y, z, {0, 0}, 3);
	}
	
	bool mayPlace(TileSource* ts, int x, int y, int z) {
		return Tile::tiles[38]->mayPlace(ts, x, y, z);
	}
	
	void addAABBs(TileSource* ts, int x, int y, int z, const AABB* aabb, std::vector<AABB>& ab) {
		Tile::tiles[38]->addAABBs(ts, x, y, z, aabb, ab);
	}
};
