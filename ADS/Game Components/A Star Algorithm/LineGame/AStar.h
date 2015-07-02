#pragma once
#include "TileMap.h"
#include "Node.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class AStar
{
private:
	TileMap^ tileMap;

	Node^ startNode;
	Node^ endNode;

	array<Point>^ path;
	array<Node^, 2>^ nodeMap;

	ArrayList^ openList;
	ArrayList^ closedList;

	Node^ getLowestF();
	void scoreNode(Node^ n);
	ArrayList^ backTrackPath();
	void switchList(Node^ currentNode);
	void addAdjacentNodes(Node^ currentNode);
	void checkAdjacentNodes(Node^ currentNode);
	int getHeuristicValue(Point currGridLocation, Point currGridDestination);
	array<Point>^ getPossibleNodeLocations(Point currentNodeLocation);


public:
	AStar(TileMap^ startTileMap);
	ArrayList^ genPath(Point startLocation, Point endLocation);
};
