#include "StdAfx.h"
#include "TileMap.h"


TileMap::TileMap(Graphics^ startCanvas)
{
	mCols = constants::MAX_COLS;
	mRows = constants::MAX_ROWS;
	tSize = constants::TILE_SIZE;

	canvas = startCanvas;
	path = gcnew ArrayList();
	nodeMap = gcnew array<Node^, 2>(mRows, mCols);
	
	createNodeMap();
}

void TileMap::clearList()
{
	path->Clear();
}

void TileMap::drawPath()
{
	Brush^ brush = gcnew SolidBrush(Color::LimeGreen);

	for(int i = 0; i < path->Count; i++)
	{
		Point temp = (Point)path[i];
		canvas->FillRectangle(brush, temp.X * tSize, temp.Y * tSize, tSize, tSize);
	}
}

void TileMap::drawMap()
{
	for(int r = 0; r < mRows; r++)
	{
		for (int c = 0; c < mCols; c++)
		{
			int x = (c * tSize);
			int y = (r * tSize);

			Brush^ b = gcnew SolidBrush(Color::White);
			canvas->FillRectangle(b, x, y, tSize, tSize);

			if (!nodeMap[c, r]->getIsWalkble())
			{
				Brush^ b = gcnew SolidBrush(Color::Orange);
				canvas->FillRectangle(b, x, y, tSize, tSize);
			}

			if (startNodeLocation != Point(0, 0))
			{
				if (nodeMap[c, r] == nodeMap[startNodeLocation.X, startNodeLocation.Y])
				{
					Brush^ b = gcnew SolidBrush(Color::Blue);
					canvas->FillRectangle(b, x, y, tSize, tSize);
				}
			}

			if (endNodeLocation != Point(0, 0))
			{
				if (nodeMap[c, r] == nodeMap[endNodeLocation.X, endNodeLocation.Y])
				{
					Brush^ b = gcnew SolidBrush(Color::Red);
					canvas->FillRectangle(b, x, y, tSize, tSize);
				}
			}

			//Draws node borders
			Pen^ pen = gcnew Pen(Color::Black);
			canvas->DrawRectangle(pen, x, y, tSize, tSize);


		}
	}
}

// Tries to retrive node at location to see if the location exsists 
bool TileMap::checkLocation(Point location) {
	if (location.X > constants::MAX_COLS || location.X < 0 || location.Y > constants::MAX_ROWS || location.Y < 0) {
		return false;
	}
	return true;
}

// Sets the node at the location to act like a wall
void TileMap::setNodeUnwalkable(Point location)
{
	nodeMap[location.X, location.Y]->setWalkable(false);
}

// Creates blank nodeMap
void TileMap::createNodeMap()
{
	for(int r = 0; r < mRows; r++)
	{
		for(int c = 0; c < mCols; c++)
		{
			nodeMap[r, c] = gcnew Node(Point(r, c), true);
		}
	}
}