#pragma once

#include "BotaniaItem.h"

class Petal : public BotaniaItem {
public:
	Petal(int id) : BotaniaItem(id - 0x100) {
		setNameID("petal_color");
		setIcon("petal",0);
	}
	
	std::string getName(const ItemInstance* instance) const{
		short data = instance->getAuxValue();
		if(data==0) return "petal_white";
		if(data==1) return "petal_orange";
		if(data==2) return "petal_magenta";
		if(data==3) return "petal_lightBlue";
		if(data==4) return "petal_yellow";
		if(data==5) return "petal_lime";
		if(data==6) return "petal_pink";
		if(data==7) return "petal_darkGray";
		if(data==8) return "petal_lightGray";
		if(data==9) return "petal_cyan";
		if(data==10) return "petal_purple";
		if(data==11) return "petal_blue";
		if(data==12) return "petal_brown";
		if(data==13) return "petal_green";
		if(data==14) return "petal_red";
		if(data==15) return "petal_black";
	}
};
