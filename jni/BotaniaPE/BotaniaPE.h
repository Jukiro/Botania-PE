#pragma once

#include "mcpe/tile/Tile.h"
#include "mcpe/item/Item.h"

#include "tile/BotaniaTile.h"
#include "tile/BotaniaFlower.h"
#include "tile/MysticalFlower.h"
#include "tile/Puredaisy.h"
#include "tile/Livingrock.h"
#include "tile/Livingwood.h"
#include "tile/PetalApothecary.h"

#include "item/BotaniaItem.h"
#include "item/Petal.h"
#include "item/Lexica.h"
#include "item/BotaniaTool.h"

class BotaniaPE {
public:
	static void tileRegistry() {
		new MysticalFlower(200);
		new PureDaisy(201); //should this be multiple data values for multiple flowers in one?
		new Livingrock(202);
		new Livingwood(203);
		new PetalApothecary(204);
	}
	
	static void itemRegistry() {
		new Lexica(500);
		new Petal(501);
		new BotaniaTool(502);
	}
};
