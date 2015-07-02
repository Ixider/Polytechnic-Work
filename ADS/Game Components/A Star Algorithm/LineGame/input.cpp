#include "StdAfx.h"
#include "input.h"


InputManager::InputManager()
{
	myProcess = gcnew MyProcess(this, &InputManager::addWall);
}

void InputManager::setMode(int mode)
{
	switch (mode)
	{
		case (int)constants::InputMode::START:
			myProcess = gcnew MyProcess(this, &InputManager::addStartLocation);
			break;
		case (int)constants::InputMode::END:
			myProcess = gcnew MyProcess(this, &InputManager::addEndLocation);
			break;
		case (int)constants::InputMode::WALL:
			myProcess = gcnew MyProcess(this, &InputManager::addWall);
			break;
	}
}

Point InputManager::convertMouseCoords(int x, int y)
{
	int tS = constants::TILE_SIZE;
	Point nodeLocation = Point(x / tS, y / tS);
	return nodeLocation;
}

bool InputManager::validateCoords(Point nodeLocation)
{
	try
	{
		if (tileMap->checkLocation(nodeLocation))
			return true;
	}
	catch (int e)
	{
		return false;
	}
}

void InputManager::takeInput(int x, int y)
{
	Point nodeLocation = convertMouseCoords(x, y);

	if (validateCoords(nodeLocation))
		myProcess(nodeLocation);
}

void InputManager::addStartLocation(Point nodeLocation)
{
	tileMap->setStartLocation(nodeLocation);
}

void InputManager::addEndLocation(Point nodeLocation)
{
	tileMap->setEndLocation(nodeLocation);
}

void InputManager::addWall(Point nodeLocation)
{
	tileMap->setNodeUnwalkable(nodeLocation);
}

