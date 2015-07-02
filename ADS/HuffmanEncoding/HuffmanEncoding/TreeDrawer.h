#pragma once

#include "BinarySearchTree.h"
using namespace::System;
using namespace::System::Drawing;

ref class TreeDrawer {
private:
	Graphics^ gfx;

public:
	TreeDrawer(Graphics^ graphics);
	void DrawTree(BinarySearchTree^ tree);
};