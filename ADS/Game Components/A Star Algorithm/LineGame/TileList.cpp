#include "StdAfx.h"
#include "TileList.h"

TileList::TileList(void)
{
	tileArray = gcnew array<Tile^>(MAX_TILES);

	tileArray[0] = gcnew Tile(gcnew Bitmap("DryGrassTile32.bmp"), true);
	
}
void TileList::setTileArrayEntry(int tileIndex, Tile^ newTile)
{
	// Not sure why this is here but it was on the hand out
}

Bitmap^ TileList::getTileBitmap(int tileIndex)
{
	// Returns the picture at the index of the tile list
	return tileArray[tileIndex]->getTileBitmap();
}
bool TileList::getIsWalkable(int tileIndex)
{
	// Returns the walkable status at the index of the tile list
	return tileArray[tileIndex]->getIsWalkable();
}