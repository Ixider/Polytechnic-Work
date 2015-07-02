#pragma once
#include "Mazegenerator.h"
#include "MazeSolver.h"
#include "Display.h"

using namespace::System;

ref class Manager {
private:
	Display^ display;
	MazeGenerator^ mg;
	MazeSolver^ ms;

public:
	Manager(Display^ Display);
	void draw();
};