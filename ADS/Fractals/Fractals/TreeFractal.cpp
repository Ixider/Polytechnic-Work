#include "stdafx.h"
#include "TreeFractal.h"

void TreeFractal::Draw(int depth) {
	Point start = Point(400, 800);
	int length = 200;

	Point nextPoint = Point(start.X, start.Y - length);

	gfx->DrawLine(gcnew Pen(Color::Black), start, nextPoint );

	recurse(nextPoint, 0, length, depth);
}

void TreeFractal::recurse(Point last, double angle, double length, int n) {
	
	if(n > 0) {
		n--;

		length /= 1.5;
		Point extended = Point(last.X, last.Y - length);
		
		float leftAngle = (angle -= 45);
		Point left = rotatePoint(angle, last, extended);
		gfx->DrawLine(gcnew Pen(Color::Black), last, left);
		recurse(left, leftAngle, length, n); 

		float rightAngle = (angle  += 90);
		Point right = rotatePoint(angle, last, extended);
		gfx->DrawLine(gcnew Pen(Color::Black), last, right);
		recurse(right, rightAngle, length, n);
	}
}


Point TreeFractal::rotatePoint(double angle, Point origin, Point rotation) {
	Point nPoint;

	double raidians = angle * Math::PI / 180;
	float s = Math::Sin(raidians);
	float c = Math::Cos(raidians);

	nPoint.X = c * (rotation.X - origin.X) - s * (rotation.Y - origin.Y) + origin.X;
	nPoint.Y = s * (rotation.X - origin.X) + c * (rotation.Y - origin.Y) + origin.Y;

	return nPoint;
}
