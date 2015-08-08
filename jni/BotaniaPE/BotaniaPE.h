#pragma once

#include "mcpe/tile/Tile.h"

#include "tile/BotaniaTile.h"
#include "tile/BotaniaFlower.h"
#include "tile/MysticalFlower.h"
#include "tile/Puredaisy.h"

class BotaniaPE {
public:
	static void tileRegistry() {
		new MysticalFlower(200);
		new PureDaisy(201);
	}
	
	static void itemRegistry() {
		
	}
};
