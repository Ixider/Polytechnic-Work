#include "StdAfx.h"
#include "SimManager.h"


SimManager::SimManager(Graphics^ mainCanvas, Graphics^ offScreenCanvas, InputManager^ sInputManager)
{
	tileMap = gcnew TileMap(offScreenCanvas);
	aStar = gcnew AStar(tileMap);

	inputManager = sInputManager;
	inputManager->SetTileMap(tileMap);
}

void SimManager::findPath()
{
	Point startLocation = tileMap->getStartLocation();
	Point endLocation = tileMap->getEndLocation();

	tileMap->setPath(aStar->genPath(startLocation, endLocation));

	
}
void SimManager::reset()
{
	tileMap->createNodeMap();
	tileMap->clearList();
}

void SimManager::display()
{
	tileMap->drawMap();
	tileMap->drawPath();
}