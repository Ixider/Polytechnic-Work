#pragma once

using namespace System;
using namespace System::Drawing;

ref class SierpinskiTriangle {
private:
	Graphics^ gfx;
	void DrawTriangle(Point a, Point b, Point c);
	void recursiveFunction(Point a, Point b, Point c, int n);
	Point findMidPoint(Point x, Point y);

public:
	SierpinskiTriangle(Graphics^ startGfx);
	void Draw(int depth);
};