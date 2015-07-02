#include "stdafx.h"
#include "KochSnowflake.h"

KochSnowFlake::KochSnowFlake(Graphics ^sGFX) {
	gfx = sGFX;
}

void KochSnowFlake::Draw(int depth) {
	int length = 530;
	PointF a = Point(400, 100);
	PointF b = Point(a.X, a.Y + length);
	b = rotatePoint(-30, a, b);

	PointF c = Point(a.X, a.Y + length);
	c = rotatePoint(30, a, c);

	array<PointF>^ points = {a, b, c};
	gfx->DrawPolygon(gcnew Pen(Color::Black), points);

	recurse(a, b, 300, depth);
	recurse(a, c, -300, depth);
	recurse(b, c, 300, depth);
	

}
int KochSnowFlake::getCurrentAngle(Point a, Point b) {

	float angle = Math::Atan2(a.Y - b.Y, a.X - b.X) * 180 / Math::PI;

	if(((int)angle % 10) != 10) {
		angle = Math::Floor(angle);
	}

	return angle;
}
void KochSnowFlake::recurse(PointF a, PointF b, int angle, int n) {
	Pen^ white = gcnew Pen(gcnew SolidBrush(Color::White), 6);
	Pen^ black = gcnew Pen(gcnew SolidBrush(Color::Black), 1);

	if(n > 0) {
		n--;

		PointF nB = findThird(a, b);
		PointF nC = findThird(b, a);
		// find the new point
		PointF nA = rotatePoint(angle, nB, nC);
		//Erase the line
		gfx->DrawLine(white, nB, nC);
		gfx->DrawLine(black, nA, nB);
		gfx->DrawLine(black, nA, nC);

		//gfx->DrawEllipse(gcnew Pen(Color::Red), a.X, a.Y, 3, 3);
		//gfx->DrawEllipse(gcnew Pen(Color::Red), b.X, b.Y, 3, 3);

		//gfx->DrawEllipse(gcnew Pen(Color::Red), nB.X, nB.Y, 3, 3);
		//gfx->DrawEllipse(gcnew Pen(Color::Red), nC.X, nC.Y, 3, 3);

		recurse(nA, nC, angle, n);
		recurse(a, nB, angle, n);
		recurse(nB, nA, angle, n);
		recurse(nC, b, angle, n);
		
	}
}
PointF KochSnowFlake::findThird(PointF a, PointF b) {
	PointF nPoint;

	nPoint.X = (a.X / 3) * 2 + (b.X / 3);
	nPoint.Y = (a.Y / 3) * 2 + (b.Y / 3);

	return nPoint;
}
PointF KochSnowFlake::rotatePoint(double angle, PointF origin, PointF rotation) {
	PointF nPoint;

	double raidians = angle * Math::PI / 180;
	float s = Math::Sin(raidians);
	float c = Math::Cos(raidians);

	nPoint.X = c * (rotation.X - origin.X) - s * (rotation.Y - origin.Y) + origin.X;
	nPoint.Y = s * (rotation.X - origin.X) + c * (rotation.Y - origin.Y) + origin.Y;

	return nPoint;
}