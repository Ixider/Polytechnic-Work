#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
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
