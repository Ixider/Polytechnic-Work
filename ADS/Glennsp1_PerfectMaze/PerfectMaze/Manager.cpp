#include "stdafx.h"
#include "Manager.h"

Manager::Manager(Display ^Display) {
	display = Display;
	mg = gcnew MazeGenerator();
	ms = gcnew MazeSolver();

}

void Manager::draw() {
	array<Node^, 2>^ maze = mg->buildMaze();
	Queue<Node^>^ path = ms->solveMaze(maze);
	display->drawMaze(maze);
	display->drawSolution(path);

}