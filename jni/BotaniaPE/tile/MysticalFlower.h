#pragma once

#include "BotaniaFlower.h"

class MysticalFlower : public BotaniaFlower {
public:
	MysticalFlower(int id) : BotaniaFlower(id) {
		setNameId("mysticalFlower");
		tex = getTextureUVCoordinateSet("flower", 0);
	}
	
	std::string getName(ItemInstance const* instance) const{
		if(instance->getAuxValue()==0) return "mysticalFlower_white";
		if(instance->getAuxValue()==1) return "mysticalFlower_orange";
		else return "mysticalFlower_color";
	}
	
	TextureUVCoordinateSet const& getTexture(signed char t, int t1) {
		if(t1==0) return getTextureUVCoordinateSet("flower", 0);
		if(t1==1) return getTextureUVCoordinateSet("flower", 1);
		if(t1==2) return getTextureUVCoordinateSet("aflower", 0);
		if(t1==3) return getTextureUVCoordinateSet("flower", 3);
		if(t1==4) return getTextureUVCoordinateSet("flower", 4);
		if(t1==5) return getTextureUVCoordinateSet("flower", 5);
		if(t1==6) return getTextureUVCoordinateSet("flower", 6);
		if(t1==7) return getTextureUVCoordinateSet("flower", 7);
		if(t1==8) return getTextureUVCoordinateSet("flower", 8);
		if(t1==9) return getTextureUVCoordinateSet("flower", 9);
		if(t1==10) return getTextureUVCoordinateSet("bflower", 0);
		if(t1==11) return getTextureUVCoordinateSet("flower", 11);
		if(t1==12) return getTextureUVCoordinateSet("flower", 12);
		if(t1==13) return getTextureUVCoordinateSet("flower", 13);
		if(t1==14) return getTextureUVCoordinateSet("flower", 14);
		if(t1==15) return getTextureUVCoordinateSet("cflower", 0);
		if(t1==16) return getTextureUVCoordinateSet("flower", 16);
	}
	
	void onRemove(TileSource* ts, int x, int y, int z){
		unsigned char data = ts->getData(x,y,z);
		ItemInstance* inst = new ItemInstance(id, 1, data);
		popResource(ts, x, y, z, inst);
	}
};
