#pragma once

using namespace System;
using namespace System::Drawing;



ref class Hexagon
{
	private:
		array<Point>^ points;
		int side;
		int h;
		int r;
		int x;
		int y;

	public:
		Hexagon(int x, int y);
		double DegreesToRadians(double degrees);
};
