#pragma once

#include "SierpinskiTriangle.h"
#include "SierpinskiCarpet.h"
#include "TreeFractal.h"
#include "KochSnowFlake.h"
#include "Circles.h"

using namespace::System;
using namespace::System::Drawing;

enum FTYPE { TRIANGLE, CARPET, TREE, SNOWFLAKE, CIRCLE };

ref class Manager {

private:
	Graphics^ gfx;

	SierpinskiTriangle^ triangle;
	SierpinskiCarpet^ carpet;
	TreeFractal^ tree;
	KochSnowFlake^ sf;
	Circles^ c;

	int validateInput(String^ string);
public:

	Manager(Graphics^ graphics);
	void Input(int mode, String^ depth);

};