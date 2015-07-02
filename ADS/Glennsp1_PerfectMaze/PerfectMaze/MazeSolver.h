#pragma once
#include "Node.h"
#include "Queue.h"
#include "Constants.h"

using namespace::System;

ref class MazeSolver {
private:
	Random^ rGen;

	System::Collections::Generic::List<Node^>^ retrievePossibleMoves(Node^ currentNode, array<Node^,2>^ maze);
public:
	MazeSolver();
	Queue<Node^>^ solveMaze(array<Node^, 2>^ maze);

};