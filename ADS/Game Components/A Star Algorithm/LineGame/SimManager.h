#pragma once

#include "TileMap.h"
#include "AStar.h"
#include "input.h"

using namespace System;

ref class SimManager 
{
	private:
		AStar^ aStar;
		TileMap^ tileMap;
		InputManager^ inputManager;

		

	public:
		SimManager(Graphics^ mainCanvas, Graphics^ offScreenCanvas, InputManager^ sInputManager);
		void reset();
		void display();
		void findPath();
};