#include "stdafx.h"
#include "Manager.h"

Manager::Manager(Graphics^ graphics) {
	gfx = graphics;

	triangle = gcnew SierpinskiTriangle(graphics);
	carpet = gcnew SierpinskiCarpet(graphics);
	tree = gcnew TreeFractal(graphics);
	sf = gcnew KochSnowFlake(graphics);
	c = gcnew Circles(graphics);
}

void Manager::Input(int mode, String^ depth) {
	
	int n = validateInput(depth);

	gfx->Clear(Color::White);
	if(mode == FTYPE::TRIANGLE) {
		triangle->Draw(n);
	} else if (mode == FTYPE::CARPET) {
		carpet->Draw(n);
	} else if (mode == FTYPE::TREE) {
		tree->Draw(n);
	} else if (mode == FTYPE::SNOWFLAKE) {
		sf->Draw(n);
	} else if (mode == FTYPE::CIRCLE) {
		c->Draw(n);
	}

}

int Manager::validateInput(String^ string) {
	int depth = -1;

	try {
		depth = Convert::ToInt16(string);
	} catch(FormatException^ e) {
	}

	return depth;
}