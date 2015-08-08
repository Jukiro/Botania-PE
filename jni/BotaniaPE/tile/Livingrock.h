#pragma once

#include "BotaniaTile.h"

class Livingrock : public BotaniaTile {
public:
	Livingrock(int id) : BotaniaTile(id, "") {
		setNameId("livingrock");
		setSoundType(Sound::SOUND_STONE);
	}	
};
