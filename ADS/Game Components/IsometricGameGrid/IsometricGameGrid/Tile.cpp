#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, bool startIsWalkable)
{
	tileBitmap = startTileBitmap;
	isWalkable = startIsWalkable;
}
