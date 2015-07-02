#include "StdAfx.h"
#include "AStar.h"

AStar::AStar(TileMap^ startTileMap)
{
    tileMap = startTileMap;
	nodeMap = tileMap->getNodeMap();
}


ArrayList^ AStar::genPath(Point startLocation, Point endLocation)
{
	openList = gcnew ArrayList();
	closedList = gcnew ArrayList();

	// Sets up starting nodes values
	startNode = nodeMap[startLocation.X, startLocation.Y];
	endNode = nodeMap[endLocation.X, endLocation.Y];


	openList->Add(startNode);
	addAdjacentNodes(startNode);
	switchList(startNode);

   while (!closedList->Contains(endNode)) {
	   Node^ currentNode = getLowestF();
	   switchList(currentNode);
	   addAdjacentNodes(currentNode);

	   if (openList->Contains(currentNode)) {
		   checkAdjacentNodes(currentNode);
	   }
   }

   ArrayList^ path = backTrackPath();
   return path;
}

ArrayList^ AStar::backTrackPath() {
   ArrayList^ path = gcnew ArrayList();
   
   Node^ currentNode = endNode;
   do
   {
	   path->Add(currentNode->getNodeLocation());
	   currentNode = currentNode->getParentNode();
   }while(currentNode !=  startNode);

   path->Add(startNode->getNodeLocation());
   path->Reverse();

   return path;
}

/*
	PRE: None
*/
void AStar::addAdjacentNodes(Node^ currentNode) { 
	Point cLocation = currentNode->getNodeLocation();
	array<Point>^ possibleLocations = getPossibleNodeLocations(cLocation);

	// Makes sure nodes are within bounds, a valid walkable node, and not on either the open or closed list
	ArrayList^ nodes = gcnew ArrayList();
	for each(Point i in possibleLocations) {
		if (i.X >= 0 && i.X < constants::MAX_COLS && i.Y >= 0 && i.Y < constants::MAX_ROWS) {
			Node^ currentANode = nodeMap[i.X, i.Y];
			if (currentANode->getIsWalkble()) {
				if (!closedList->Contains(currentANode) && !openList->Contains(currentANode)) {
					currentANode->setParentNode(currentNode);
					scoreNode(currentANode);
					openList->Add(currentANode);
				}
			}
		}
	}
}
/*
	POST: Valid nodes are scored and added to the open list
*/

/*
	PRE: Current node must have adjacent no
*/
void AStar::checkAdjacentNodes(Node^ currentNode) { // Checks current node for adjacent nodes that are already on the open list
	Point cLocation = currentNode->getNodeLocation();
	array<Point>^ possibleLocations = getPossibleNodeLocations(cLocation);

	for each(Point i in possibleLocations) {
		Node^ currentANode = nodeMap[i.X, i.Y];
		if (openList->Contains(currentANode)) { // Adj nodes already on the openlist are checked for a more cost effecient path
			if (currentANode->getG() < (currentNode->getG() + constants::MOVMENT_COST)) {
				currentANode->setParentNode(currentNode->getParentNode());
				scoreNode(currentANode);
			}
		}
	}
}
/*
	POST: 
*/

void AStar::scoreNode(Node^ n){
	int h = getHeuristicValue(n->getNodeLocation(), endNode->getNodeLocation()) * constants::MOVMENT_COST;
	n->setH(h);
	// Tricky situation here when it comes to adding diagonals, because the diagonal G score is +14
	// Maybe reuse the Manhatten a score again to check if its 0 or 1 away from its parent
	int g = n->getParentNode()->getG() + constants::MOVMENT_COST;
	n->setG(g);

	int f = (n->getG() + n->getH());
	n->setF(f);
}

Node^ AStar::getLowestF() {
	Node^ nodeWithLowestResult = (Node^)openList[0];

	for(int i = 0; i < openList->Count; i++) {
		Node^ tempNode = (Node^)openList[i];
		if(tempNode->getF() < nodeWithLowestResult->getF()) {
			nodeWithLowestResult = tempNode;
		}
	}

	return nodeWithLowestResult;
}

int AStar::getHeuristicValue(Point currGridLocation, Point currGridDestination) {
    int xH = Math::Abs(currGridLocation.X - currGridDestination.X);
	int yH = Math::Abs(currGridLocation.Y - currGridDestination.Y);

	int h = xH + yH;
	return h;
}

void AStar::switchList(Node^ currentNode) {
	openList->Remove(currentNode);
	closedList->Add(currentNode);
}

array<Point>^ AStar::getPossibleNodeLocations(Point cLocation) {
	array<Point>^ possibleLocations = { Point(cLocation.X - 1, cLocation.Y),
									 //	Point(cLocation.X - 1, cLocation.Y - 1),
									 	Point(cLocation.X, cLocation.Y - 1),
									 //	Point(cLocation.X + 1, cLocation.Y - 1),
										Point(cLocation.X + 1, cLocation.Y),
									 //	Point(cLocation.X + 1, cLocation.Y + 1),
										Point(cLocation.X, cLocation.Y + 1), 
									 //	Point(cLocation.X - 1, cLocation.Y + 1) 
									  };
	return possibleLocations;
}