#pragma once
#include "Node.h"
#include "Queue.h"
#include "Constants.h"

using namespace::System;

ref class MazeGenerator {
private:
	Random^ rGen;
	//Maze Generation Methods
	void createPath(array<Node^, 2>^ maze);
	bool allNodesVisisted(array<Node^,2>^ maze);
	void breakWall(Node^ currentNode, Node^ nextNode);
	System::Collections::Generic::List<Node^>^ retrieveUnvistedAdjacentNodes(Node^ currentNode, array<Node^, 2>^ maze);
	void resetVisitedCells(array<Node^, 2>^ maze);
	

public:
	MazeGenerator();
	array<Node^,2>^ buildMaze();
};