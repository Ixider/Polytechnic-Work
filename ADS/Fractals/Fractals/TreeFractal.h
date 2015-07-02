#pragma once

using namespace::System;
using namespace::System::Drawing;

ref class TreeFractal {	

private:
	Graphics^ gfx;
	Point rotatePoint(double angle, Point origin, Point rotation);
	void recurse(Point last, double angle, double length, int n);		

public:
	TreeFractal(Graphics^ sGfx){ gfx = sGfx; }
	void Draw(int depth);

};