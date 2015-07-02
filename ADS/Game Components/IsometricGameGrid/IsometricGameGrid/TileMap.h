#pragma once
#include "TileList.h"
#include "Tile.h"

#define MAX_COLS 20
#define MAX_ROWS 20

#define TILE_WIDTH 62
#define TILE_HEIGHT 31


using namespace System::IO;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileMap
{
private:
	//TileList^ tileList;
	array<int, 2>^ map;
	array<Tile^, 2>^ nodeMap;
	Graphics^ canvas;

	void createMapFromFile(String^ mapFileName);

public:
	TileMap(Graphics^ startCanvas);
	TileList^ tileList;
	void drawMap();


	array<Tile^,2>^ getNodeMap() { return nodeMap; }
	bool checkLocation(int xPos, int yPos, int frameWidth, int frameHeight);
	int getMapValue(int row, int col) { return map[row, col]; }
	void setMapValue(int row, int col, int tileValue) { map[row, col] = tileValue; }

};
