#pragma once

#include "texture/TextureUVCoordinateSet.h"
#include "../../util/AABB.h"
#include "../../tile/Tile.h"
#include <cmath>

class TileSource;
#include "Tessellator.h"
class TilePos;

const float PI = 3.14159;

// Size : 72740
class TileTessellator
{
public:
	static TileTessellator *instance;

public:
	char filler1[4];				// 0
	TileSource *tileSource;			// 4
	TextureUVCoordinateSet forcedUV;// 8
	bool useForcedUV;				// 40
	char filler2[623];				// 41
	Tessellator* tess;				// 664
	AABB bounds;					// 668

public:
	bool tessellateInWorld(Tile *, const TilePos &, bool);
	void tessellateBlockInWorld(Tile *, const TilePos &);
	bool tessellateCrossInWorld(Tile*, const TilePos&, bool);
	bool tessellateCrossTexture(Tile*, unsigned char, float, float, float, bool);
	uint getLightColor(const TilePos &);
	void tex1(uint);
	bool canRender(int);
	
	void setRenderBounds(float x1, float y1, float z1, float x2, float y2, float z2) {
		bounds = AABB(x1, y1, z1, x2, y2, z2);
	}
	
	bool isOn(TileSource* ts, Tile* tile, int x, int y, int z) {
		if(ts->getTilePtr(x, y, z) == tile) return true;
	}
	
	bool tessellateBotaniaApothecaryInWorld(Tile* tile, TilePos const& pos){
		useForcedUV = true;
		int x = pos.x, y = pos.y, z = pos.z;
		
		forcedUV = tile->getTextureUVCoordinateSet("cobblestone",0);
		
		setRenderBounds(0.0, 0.0, 0.0, 1.0, 0.125, 1.0);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.0625, 0.125, 0.0625, 0.9375, 0.1875, 0.9375);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.125, 0.1875, 0.125, 0.875, 0.25, 0.875); //appearantly I do...
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.3125, 0.25, 0.3125, 0.6875, 0.75, 0.6875);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.25, 0.75, 0.25, 0.75, 0.8125, 0.75);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.1875, 0.8125, 0.1875, 0.8125, 0.875, 0.8125);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.125, 0.875, 0.1875, 0.1875, 1.25, 0.8125);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.1875, 0.875, 0.125, 0.8125, 1.25, 0.1875);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.8125, 0.875, 0.1875, 0.875, 1.25, 0.8125);
		tessellateBlockInWorld(tile, pos);
		
		setRenderBounds(0.1875, 0.875, 0.8125, 0.8125, 1.25, 0.875);
		tessellateBlockInWorld(tile, pos);
		
		int data = tileSource->getData(x, y, z);
		if(data==1){
			forcedUV = tile->getTextureUVCoordinateSet("flowing_water",0);
			setRenderBounds(0.1875, 0.875, 0.1875, 0.8125, 1.1875, 0.8125);
			tessellateBlockInWorld(tile, pos);
		}
		if(data==2){
			forcedUV = tile->getTextureUVCoordinateSet("flowing_lava",0);
			setRenderBounds(0.1875, 0.875, 0.1875, 0.8125, 1.1875, 0.8125);
			tessellateBlockInWorld(tile, pos);
		}
		
		useForcedUV = false;
	}
	
	bool tessellateBotaniaFlowerInWorld(Tile* tile, TilePos const& pos) {
		int x = pos.x;
		int y = pos.y;
		int z = pos.z;
		
        /*forcedUV = tile->getTextureUVCoordinateSet("brewing_stand", 0);
		useForcedUV = true;
		
        setRenderBounds(0.4375, 0.0, 0.4375, 0.5625, 0.875, 0.5625);
        tessellateBlockInWorld(tile, pos);
 
        forcedUV = tile->getTextureUVCoordinateSet("brewing_stand_base", 0);
		
        setRenderBounds(0.5625, 0.0, 0.3125, 0.9375, 0.125, 0.6875);
        tessellateBlockInWorld(tile, pos);
		
        setRenderBounds(0.125, 0.0, 0.0625, 0.5, 0.125, 0.4375);
        tessellateBlockInWorld(tile, pos);
		
        setRenderBounds(0.125, 0.0, 0.5625, 0.5, 0.125, 0.9375);
        tessellateBlockInWorld(tile, pos);
		
        useForcedUV = false;*/
      
        /*TextureUVCoordinateSet stand_uv = tile->getTextureUVCoordinateSet("flower", 0);

        float v0 = stand_uv.minV;
        float v1 = stand_uv.maxV;
        int data = tileSource->getData(x, y, z);
 
        for(int i = 0; i < 3; ++i) {
            float helper = i * PI * 2.0 / 3.0 + (PI / 2);
            float u0 = 8.0F;
            float u1 = stand_uv.maxU;
 
            if ((data & 1 << i) != 0) {
               u1 = stand_uv.minU;
            }
 
            float x0 = pos.x + 0.5;
            float x1 = pos.x + 0.5 + sin(helper) * 8.0F / 16.0F;
            float z0 = pos.z + 0.5;
            float z1 = pos.z + 0.5 + cos(helper) * 8.0F / 16.0F;
            tess->vertexUV(x0, (pos.y + 1), z0, u0, v0);
            tess->vertexUV(x0, (pos.y + 0), z0, u0, v1);
            tess->vertexUV(x1, (pos.y + 0), z1, u1, v1);
            tess->vertexUV(x1, (pos.y + 1), z1, u1, v0);
            tess->vertexUV(x1, (pos.y + 1), z1, u1, v0);
            tess->vertexUV(x1, (pos.y + 0), z1, u1, v1);
            tess->vertexUV(x0, (pos.y + 0), z0, u0, v1);
            tess->vertexUV(x0, (pos.y + 1), z0, u0, v0);
        }*/
		tessellateCrossInWorld(tile, pos, true);	
		tessellateCrossTexture(tile, 0, x, y, z, true);
        return true;
	}
	
	bool tessellateRedstoneTileInWorld(Tile* tile, TilePos const& pos) {
		int x = pos.x;
		int y = pos.y;
		int z = pos.z;
		
		int data = tileSource->getData(x, y, z);
		
		setRenderBounds(0, 0, 0, 1, 0.06, 1);
		tessellateBlockInWorld(tile, pos);
		
		return true;
	}
	
	bool tessellateRepeaterTileInWorld(Tile* tile, TilePos const& pos) {
		int x = pos.x;
		int y = pos.y;
		int z = pos.z;
		
		int data = tileSource->getData(x, y, z);
		
        forcedUV = tile->getTexture(0, 0);
		useForcedUV = true;
		
        setRenderBounds(0, 0, 0, 1, 0.125, 1);
        tessellateBlockInWorld(tile, pos);
		
		forcedUV = tile->getTextureUVCoordinateSet("torch_off", 0);
		
        setRenderBounds(0.4350, 0, 0.3775, 0.5625, 0.4425, 0.50);
        tessellateBlockInWorld(tile, pos);
		
        setRenderBounds(0.4350, 0, 0.1225, 0.5625, 0.4425, 0.2425);
        tessellateBlockInWorld(tile, pos);
	
		useForcedUV = false;
		
		return true;
	}
	
	/*bool tessellateBotaniaFlowerInWorld(Tile* tile, TilePos const& pos) {
		int x = pos.x;
		int y = pos.y;
		int z = pos.z;
		
		
		
        return true;
	}*/
	
	bool tessellateBannerTileInWorld(Tile* tile, const TilePos& pos) {
		useForcedUV = true;
		
		setRenderBounds(0, 0, 0, 0, 0, 0);
		tessellateBlockInWorld(tile, pos);
		
		//Banner
		forcedUV = tile->getTexture(3, 0);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.625, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.625, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(5, 0);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(2, 0);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(4, 0);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.625, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(1, 0);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(0, 0);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 0.0625, pos.z + 0.625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 0.0625, pos.z + 0.625, forcedUV.minU, forcedUV.minV);
		
		//Bottom base
		forcedUV = tile->getTexture(3, 1);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.4375, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.4375, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(5, 1);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(2, 1);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(4, 1);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.5625, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(0, 1);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.4375, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.4375, forcedUV.maxU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.5625, pos.y, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.4375, pos.y, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(1, 1);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.4375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.5625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.maxV);
		
		//Top base
		forcedUV = tile->getTexture(3, 2);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.minV + 0.0078125);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV + 0.0078125);
		
		forcedUV = tile->getTexture(5, 2);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.minU, forcedUV.minV + 0.0078125);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV + 0.0078125);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		
		forcedUV = tile->getTexture(2, 2);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(4, 2);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.maxV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.4375, forcedUV.maxU, forcedUV.maxV);
		
		forcedUV = tile->getTexture(1, 2);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.4375, forcedUV.minU, forcedUV.minV + 0.0078125);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.9375, pos.z + 0.5625, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.9375, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV + 0.0078125);
		
		forcedUV = tile->getTexture(0, 2);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.4375, forcedUV.maxU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.4375, forcedUV.minU, forcedUV.minV);
		tess->vertexUV(pos.x + 0.9375, pos.y + 1.8125, pos.z + 0.5625, forcedUV.minU, forcedUV.minV + 0.0078125);
		tess->vertexUV(pos.x + 0.0625, pos.y + 1.8125, pos.z + 0.5625, forcedUV.maxU, forcedUV.minV + 0.0078125);
		
		useForcedUV = false;
		return true;
	}
};
