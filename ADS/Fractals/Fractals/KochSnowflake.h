#pragma once

using namespace::System;
using namespace::System::Drawing;

public ref class KochSnowFlake {
private:
	Graphics^ gfx;
	void recurse(PointF a, PointF b, int angle, int n);
	PointF findThird(PointF a, PointF b);
	int getCurrentAngle(Point a, Point b);

public:
	KochSnowFlake(Graphics^ sGFX);
	PointF rotatePoint(double angle, PointF origin, PointF rotation);
	void Draw(int depth);
};