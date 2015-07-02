#include "StdAfx.h"
#include "TileMap.h"


TileMap::TileMap(Graphics^ startCanvas) {
	tileList = gcnew TileList();
	map = gcnew array<int, 2> (MAX_ROWS, MAX_COLS);
	nodeMap = gcnew array<Tile^, 2>(MAX_ROWS, MAX_COLS);
	canvas = startCanvas;
}

void TileMap::drawMap() {
	// Draws the map in Tile size parts one at a time
	Point l = Point(0,0);

	for(int y = 0; y < MAX_COLS; y++) {
		for (int x = MAX_ROWS - 1; x >= 0; x--) {

			l.X = (x * TILE_WIDTH / 2) + (y * TILE_WIDTH / 2);
			l.Y = (y * TILE_HEIGHT / 2) - (x * TILE_HEIGHT / 2);
	
			l.Y += (TILE_HEIGHT * MAX_COLS) / 2;
			canvas->DrawImage(tileList->getTileBitmap(getMapValue(y, x)), l.X, l.Y);

			//Pen^ pen = gcnew Pen(Color::Black);
			//canvas->DrawRectangle(pen, l.X, l.Y, TILE_WIDTH, TILE_HEIGHT);
		}
	}
}

// Takes in the x and y positions of the sprite calling it aswell as that sprites frame dimensions to check the status of the tile its current trying to move over
bool TileMap::checkLocation(int xPos, int yPos, int frameWidth, int frameHeight) {
	int tileX = xPos / TILE_WIDTH;
	int tileY = yPos / TILE_HEIGHT;
	if(!tileList->getIsWalkable(getMapValue(tileX, tileY)))
	{
		return false;
	}
	return true;
}



void TileMap::createMapFromFile(String^ mapFileName) {
	// Creates a new Stream Reader to connect with CSV file
	StreamReader^ mapReader = gcnew StreamReader(mapFileName);

	// A holds a string of the entire first line of the csv
	String^ line;
	for(int r = 0; r < MAX_ROWS; r++) {
		// Reads the first line of the csv into the String line 
		line = mapReader->ReadLine();
		// Splits the entire first line into parts seperated by a ,
		array<String^>^ parts = line->Split(',');

		for(int c = 0; c < MAX_COLS; c++) {
			// Converts the value from each place in the parts array to a int
			int tileValueFromFile = Convert::ToInt32(parts[c]);
			setMapValue(r, c, tileValueFromFile);
			nodeMap[r, c] = gcnew Tile(tileList->getTileBitmap(tileValueFromFile), tileList->getIsWalkable(tileValueFromFile));
		}
	}
	// Closes the streamReader used to read from the file
	mapReader->Close();
}
