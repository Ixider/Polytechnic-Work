#pragma once

using namespace System;
using namespace System::Drawing;


ref class Tile
{
private: 
	Bitmap^ tileBitmap;
	bool isWalkable;

public:
	Tile(Bitmap^ startTileBitmap, bool startIsWalkable);

	Bitmap^ getTileBitmap() { return tileBitmap; }
	bool getIsWalkable() { return isWalkable; }
};
