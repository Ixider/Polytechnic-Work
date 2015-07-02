#include "stdafx.h"
#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle(Graphics^ startGfx) {
	gfx = startGfx;
}

void SierpinskiTriangle::Draw(int depth) {
	Point top = Point(400, 100);
	Point bottomLeft = Point(0, 700);
	Point bottomRight = Point(800, 700);

	array<Point, 1>^ triangle = { top, bottomLeft, bottomRight };

	DrawTriangle(top, bottomLeft, bottomRight);
	recursiveFunction(top, bottomLeft, bottomRight, depth);
}

void SierpinskiTriangle::recursiveFunction(Point a, Point b, Point c, int n) {
	
	if(n > 0) {
		n--;

		Point nA = findMidPoint(a, b);
		Point nB= findMidPoint(b, c);
		Point nC = findMidPoint(a, c);

		DrawTriangle(nA, nB, nC);
		
		recursiveFunction(a, nA, nC, n);
		recursiveFunction(b, nA, nB, n);
		recursiveFunction(c, nC, nB, n);
	}
}

void SierpinskiTriangle::DrawTriangle(Point a, Point b, Point c) {
	array<Point,1>^ points = {a, b, c};
	gfx->DrawPolygon(gcnew Pen(Color::Blue), points);	
}

Point SierpinskiTriangle::findMidPoint(Point one, Point two){
	Point midPoint;

	midPoint.X = (one.X + two.X) / 2;
	midPoint.Y = (one.Y + two.Y) / 2;

	return midPoint;
}
