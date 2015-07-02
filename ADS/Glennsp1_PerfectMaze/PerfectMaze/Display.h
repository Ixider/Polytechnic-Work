#pragma once
#include "Node.h"
#include "Constants.h"
#include "Queue.h"

using namespace::System;
using namespace::System::Drawing;

ref class Display {
private:
	Graphics^ gfx;

	void drawCell(Point cellAddress, Node^ node);
public:
	Display(Graphics^ graphics);
	void drawMaze(array<Node^,2>^ maze);
	void drawSolution(Queue<Node^>^ path);
};