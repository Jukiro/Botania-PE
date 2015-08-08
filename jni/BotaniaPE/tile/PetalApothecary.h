#pragma once
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/item/TileItem.h"

class PetalApothecary : public Tile {
public:
	static PetalApothecary* petalApothecary;
	
	virtual int getResource(int, Random *);
	virtual int getResourceCount(Random *);
	virtual TextureUVCoordinateSet const& getTexture(signed char, int);
	virtual bool isObstructingChests(TileSource *, int, int, int);
	virtual bool isPathfindable(TileSource *, int, int, int);
	
	PetalApothecary(int, Material const*);
};
