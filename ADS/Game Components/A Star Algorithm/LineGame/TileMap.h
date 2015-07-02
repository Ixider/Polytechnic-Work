#pragma once

#include "Node.h"
#include "constants.h"

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
	int mCols;
	int mRows;
	int tSize;

	ArrayList^ path;
	Graphics^ canvas;
	array<Node^, 2>^ nodeMap;

	Point startNodeLocation;
	Point endNodeLocation;

public:
	TileMap(Graphics^ startCanvas);

	void drawMap();
	void drawPath();
	void createNodeMap();

	void setPath(ArrayList^ newPath) { path = newPath; }
	bool checkLocation(Point location);

	void clearList();
	void setNodeUnwalkable(Point location);
	array<Node^,2>^ getNodeMap() { return nodeMap; }

	void setStartLocation(Point location) { startNodeLocation = location; }
	Point getStartLocation() { return startNodeLocation; }

	void setEndLocation(Point location) { endNodeLocation = location; }
	Point getEndLocation() { return endNodeLocation; }
};
