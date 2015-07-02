#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Circles {
private:
	Graphics^ gfx;
	int getCurrentAngle(PointF a, PointF b);
	PointF rotatePoint(double angle, PointF origin, PointF rotation);
public:
	Circles(Graphics^ sgfx);
	void Draw(int depth);
	void recurse(PointF point, int length, int n);
};