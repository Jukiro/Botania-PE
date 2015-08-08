#pragma once

#include "mcpe/tile/Tile.h"

#include "tile/BotaniaTile.h"
#include "tile/BotaniaFlower.h"
#include "tile/MysticalFlower.h"
#include "tile/Puredaisy.h"
#include "tile/Livingrock.h"

class BotaniaPE {
public:
	static void tileRegistry() {
		new MysticalFlower(200);
		new PureDaisy(201); //should this be multiple data values for multiple flowers in one?
		new Livingrock(202);
	}
	
	static void itemRegistry() {
		
	}
};
