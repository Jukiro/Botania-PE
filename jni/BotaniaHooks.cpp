#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include <mcpe/item/Item.h>
#include <mcpe/tile/Tile.h>
#include <mcpe/client/renderer/TileTessellator.h>
#include <mcpe/client/MinecraftClient.h>
#include <mcpe/client/renderer/ScreenRenderer.h>
#include <mcpe/client/gui/Gui.h>

#include "BotaniaPE/BotaniaPE.h"

bool (*_TileTessellator$tessellateInWorld)(TileTessellator*, Tile*, const TilePos&, bool);
bool TileTessellator$tessellateInWorld(TileTessellator* self, Tile* tile, const TilePos& pos, bool b) {
	switch(tile->id) {
		case 200:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		case 201:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		case 202:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		case 203:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		case 204:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		case 205:
			return self->tessellateBotaniaFlowerInWorld(tile, pos);
			break;
		default:
			return _TileTessellator$tessellateInWorld(self, tile, pos, b);
	}
}


void (*_MinecraftClient$init)(MinecraftClient*);
void MinecraftClient$init(MinecraftClient* c) {
	_MinecraftClient$init(c);

}


void (*_Item$initItems)();
void Item$initItems() {
	_Item$initItems();
	
	BotaniaPE::itemRegistry;
}


void (*_Tile$initTiles)();
void Tile$initTiles() {
	_Tile$initTiles();
	
	BotaniaPE::tileRegistry();
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::initItems, 					(void*) &Item$initItems, 						(void**) &_Item$initItems);
	MSHookFunction((void*) &Tile::initTiles, 					(void*) &Tile$initTiles, 						(void**) &_Tile$initTiles);
	MSHookFunction((void*) &MinecraftClient::init, 				(void*) &MinecraftClient$init, 					(void**) &_MinecraftClient$init);
	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, 	(void**) &_TileTessellator$tessellateInWorld);
	
	return JNI_VERSION_1_2;
}
