#pragma once

#include "TileMap.h"

using namespace System;
using namespace System::Drawing;


ref class InputManager
{
	private:
		delegate void MyProcess(Point nodeLocation);
		MyProcess^ myProcess;

		TileMap^ tileMap;

		void addStartLocation(Point nodeLocation);
		void addEndLocation(Point nodeLocation);
		void addWall(Point nodeLocation);

		Point convertMouseCoords(int x, int y);
		bool validateCoords(Point point);

	public:
		InputManager();
		void setMode(int inputType);
		void takeInput(int x, int y);
		void SetTileMap(TileMap^ newMap) { tileMap = newMap; }
};