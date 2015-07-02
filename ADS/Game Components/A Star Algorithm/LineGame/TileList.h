#pragma once
#include "Tile.h"
#include "Node.h"

#define MAX_TILES 1

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
{
private:
	array<Tile^>^ tileArray;

public:
	TileList(void);

	Bitmap^ getTileBitmap(int tileIndex);
	bool getIsWalkable(int tileIndex);
	void setTileArrayEntry(int tileIndex, Tile^ newTile);
};
