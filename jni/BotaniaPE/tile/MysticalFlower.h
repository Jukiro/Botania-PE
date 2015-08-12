#pragma once

#include "BotaniaFlower.h"

class MysticalFlower : public BotaniaFlower {
public:
	MysticalFlower(int id) : BotaniaFlower(id) {
		setNameId("mysticalFlower");
		tex = getTextureUVCoordinateSet("flower", 0);
		destroyTime = 0.0;
	}
	
	std::string getName(ItemInstance const* instance) const{
		if(instance->getAuxValue()==0) return "mysticalFlower_white";
		else if(instance->getAuxValue()==1) return "mysticalFlower_orange";
		else return "mysticalFlower_color";
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1) {
		switch(t1){
		case 0:
			return getTextureUVCoordinateSet("flower", 0);
			break;
		case 1:
			return getTextureUVCoordinateSet("flower", 1);
			break;
		case 2:
			return getTextureUVCoordinateSet("aflower", 0);
			break;
		case 3:
			return getTextureUVCoordinateSet("flower", 3);
			break;
		case 4:
			return getTextureUVCoordinateSet("flower", 4);
			break;
		case 5:
			return getTextureUVCoordinateSet("flower", 5);
			break;
		case 6:
			return getTextureUVCoordinateSet("flower", 6);
			break;
		case 7:
			return getTextureUVCoordinateSet("flower", 7);
			break;
		case 8:
			return getTextureUVCoordinateSet("flower", 8);
			break;
		case 9:
			return getTextureUVCoordinateSet("flower", 9);
			break;
		case 10:
			return getTextureUVCoordinateSet("bflower", 0);
			break;
		case 11:
			return getTextureUVCoordinateSet("flower", 11);
			break;
		case 12:
			return getTextureUVCoordinateSet("flower", 12);
			break;
		case 13:
			return getTextureUVCoordinateSet("flower", 13);
			break;
		case 14:
			return getTextureUVCoordinateSet("flower", 14);
			break;
		case 15:
			return getTextureUVCoordinateSet("cflower", 0);
			break;
		case 16:
			return getTextureUVCoordinateSet("cflower", 0);
			break;
		case 17:
			return getTextureUVCoordinateSet("cflower", 0);
			break;
		case 18:
			return getTextureUVCoordinateSet("cflower", 0);
			break;
		default:
			return getTextureUVCoordinateSet("flower",16);
			break;
		}
	}
	
	void onRemove(TileSource* ts, int x, int y, int z){
		unsigned char data = ts->getData(x,y,z);
		ItemInstance* inst = new ItemInstance(id, 1, data);
		popResource(ts, x, y, z, inst);
	}
};
