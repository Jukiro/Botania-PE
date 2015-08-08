#pragma once

#include "mcpe/tile/Tile.h"
#include "mcpe/item/ItemInstance.h"

class BotaniaTile : public Tile {	
public:
	BotaniaTile(int id, Material const* ma) : Tile(id, ma) {
		init();
		Tile::solid[id] = false;
		Tile::lightBlock[id] = 0;
		new TileItem(id-0x100);
	}
	
	BotaniaTile(int id, std::string tex, Material const* ma) : Tile(id, tex, ma) {
		init();
		Tile::solid[id] = false;
		Tile::lightBlock[id] = 0;
		new TileItem(id-0x100);
	}
};
