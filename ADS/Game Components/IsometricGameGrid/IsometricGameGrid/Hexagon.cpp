#include "StdAfx.h"
#include "Hexagon.h"

#define SIDE = 10;

Hexagon::Hexagon(int x, int y)
{
	h = Math::Sin(DegreesToRadians(30)) * side;
	r = Math::Cos(DegreesToRadians(30)) * side;

	//array<Point>^ y = gcnew array<Point>(6);
	//for (int i = 0; i < 6; i++){
	//	float angle = 2 * (3.14159265358979323846) / 6 * i;
	//	float x_i = 30 + 25 * Math::Cos(angle);
	//	float y_i = 30 + 25 * Math::Sin(angle);
	//	y[i] = Point(x_i, y_i);
	//}
	//mainCanvas->DrawLine(gcnew Pen(Color::Black), y[0], y[5]);
	//mainCanvas->DrawLines(gcnew Pen(Color::Black), y);
}

double Hexagon::DegreesToRadians(double degrees) {
	double pi = Math::Atan(1) * 4;
	return degrees * pi / 180;
}