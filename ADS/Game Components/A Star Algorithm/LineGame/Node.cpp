#include "StdAfx.h"
#include "Node.h"

Node::Node(Point nodeGridLocation, bool startIsWalkable)
{
	parent = nullptr;

	H = 0;
	G = 0;
	F = 0;

	isWalkable = startIsWalkable;
	nodeLocation = nodeGridLocation;
}	

