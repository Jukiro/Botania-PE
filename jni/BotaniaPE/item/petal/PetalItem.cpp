#include "PetalItem.h"

PetalItem* PetalItem::petalItem = NULL;

PetalItem::PetalItem(int id) : Item(id - 256) {
	setNameID("petal_color");
	setIcon("petal",0);
	setStackedByData(true);
}

/*TextureUVCoordinateSet PetalItem::getIcon(int i1, int i2, bool b) const{
	return getTextureUVCoordinateSet("petal",0);
}*/

std::string PetalItem::getName(const ItemInstance *inst) const{
	switch(inst->getAuxValue()){
		case 0:
			return "petal_white";
			break;
		case 1:
			return "petal_orange";
			break;
		case 2:
			return "petal_magenta";
			break;
		case 3:
			return "petal_lightBlue";
			break;
		case 4:
			return "petal_yellow";
			break;
		case 5:
			return "petal_lime";
			break;
		case 6:
			return "petal_pink";
			break;
		case 7:
			return "petal_darkGray";
			break;
		case 8:
			return "petal_lightGray";
			break;
		case 9:
			return "petal_cyan";
			break;
		case 10:
			return "petal_purple";
			break;
		case 11:
			return "petal_blue";
			break;
		case 12:
			return "petal_brown";
			break;
		case 13:
			return "petal_green";
			break;
		case 14:
			return "petal_red";
			break;
		case 15:
			return "petal_white";
			break;
		
	}
}
