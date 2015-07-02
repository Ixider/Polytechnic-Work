#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Node
{
private:
	int H;
	int G;
	int F;
	bool isWalkable;
	Point nodeLocation;

public:
	Node(Point nodeGridLocation, bool startIsWalkable);

	Node^ parent;
	
	int getH() { return H; }
	int getG() { return G; }
	int getF() { return F; }
	void setH(int value) { H = value; }
	void setG(int value) { G = value; } 
	void setF(int value) { F = value; }

	bool getIsWalkble() { return isWalkable; }
	void setWalkable(bool value) { isWalkable = value; }

	Point getNodeLocation() { return nodeLocation; }

	Node^ getParentNode() { return parent; }
	void setParentNode(Node^ currentNode) { parent = currentNode; }

};
