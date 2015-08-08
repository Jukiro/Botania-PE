#pragma once

#include "minecraftpe/level/TileSource.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/ParticleType.h"
#include "minecraftpe/util/Vec3.h"

#include "FlowerTile.h"

class Puredaisy : public FlowerTile {
public:
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual int getResource(int, Random*);
	virtual int getResourceCount(Random*);
	virtual TextureUVCoordinateSet const& getTexture(signed char, int);
	
	Puredaisy(int, Material const*);
};
