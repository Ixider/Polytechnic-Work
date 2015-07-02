#include "stdafx.h"
#include "Circles.h"

Circles::Circles(System::Drawing::Graphics^ sgfx) {
	gfx = sgfx;
}

void Circles::Draw(int depth) {

	PointF a = Point(250, 250);

	List<PointF>^ points = gcnew List<PointF>();

	points->Add(a);

	recurse(a, 300, depth);
}

void Circles::recurse(PointF point, int length, int n) {
	if(n > 0) {
		n--;
		gfx->DrawEllipse(gcnew Pen(Color::Black), (int)point.X, (int)point.Y, length, length); 

		int radius = length / 2;
		recurse(Point(point.X - radius + (radius/2), (point.Y + radius) - (radius/2)), radius, n);
		recurse(Point((point.X + length) - (radius/2), (point.Y + radius) - (radius/2)), radius, n);

		recurse(Point((point.X + radius) - (radius/2), point.Y - radius + (radius/2)), radius, n);
		recurse(Point((point.X + radius) - (radius/2),(point.Y + length) - (radius/2)), radius, n);
	}
}

int Circles::getCurrentAngle(PointF a, PointF b) {

	int angle = Math::Atan2(a.Y - b.Y, a.X - b.X) * 180 / Math::PI;

	return angle;
}

PointF Circles::rotatePoint(double angle, PointF origin, PointF rotation) {
	PointF nPoint;

	double raidians = angle * Math::PI / 180;
	float s = Math::Sin(raidians);
	float c = Math::Cos(raidians);

	nPoint.X = c * (rotation.X - origin.X) - s * (rotation.Y - origin.Y) + origin.X;
	nPoint.Y = s * (rotation.X - origin.X) + c * (rotation.Y - origin.Y) + origin.Y;

	return nPoint;
}