#include "stdafx.h"
#include "Display.h"

Display::Display(Graphics^ graphics) {
	gfx = graphics;
}

void Display::drawMaze(array<Node^,2>^ maze) {
	maze[0,0]->Visited = true;
	for(int i = 0; i < Constants::MAX_COLS; i++) {
		for(int j = 0; j < Constants::MAX_ROWS; j++) {
			Point cellAddress = Point(i, j);
			Node^ currentNode = maze[i, j];
			drawCell(cellAddress, currentNode);
		}
	}
}

void Display::drawCell(Point cellAddress, Node^ node) {
	Pen^ p = gcnew Pen(Color::Black);

	int sX = cellAddress.X * Constants::CELL_SIZE;
	int sY = cellAddress.Y * Constants::CELL_SIZE;

	if(node->Visited) {
		gfx->FillRectangle(gcnew SolidBrush(Color::LightBlue), sX, sY, Constants::CELL_SIZE, Constants::CELL_SIZE);
	}

	// Draws North boundary to the screen
	if(node->North) {
		int x2 = sX + Constants::CELL_SIZE;
		gfx->DrawLine(p, sX, sY, x2, sY);
	}
	// Draws East boundary to the screen
	if(node->East) {
		int x = sX + Constants::CELL_SIZE;
		int y2 = sY + Constants::CELL_SIZE;

		gfx->DrawLine(p, x, sY, x, y2);
	}

	// Draws South boundary to the screen
	if(node->South) {
		int x2 = sX + Constants::CELL_SIZE;
		int y = sY + Constants::CELL_SIZE;

		gfx->DrawLine(p, sX, y, x2, y);
	}
	// Draws West boundary to the screen
	if(node->West) {
		int y2 = sY + Constants::CELL_SIZE;
		gfx->DrawLine(p, sX, sY, sX, y2);
	}
}

void Display::drawSolution(Queue<Node^>^ path) {
	while(!path->IsEmpty()) {
		Node^ currentNode = path->Pop();
		Point ca = currentNode->Address;
		gfx->FillRectangle(gcnew SolidBrush(Color::LightGreen), ca.X * Constants::CELL_SIZE + 1,
																ca.Y * Constants::CELL_SIZE + 1,
																Constants::CELL_SIZE - 1,
																Constants::CELL_SIZE - 1);
	}
}