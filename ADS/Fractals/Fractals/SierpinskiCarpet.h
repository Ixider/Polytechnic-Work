#pragma once

using namespace System;
using namespace System::Drawing;

ref class SierpinskiCarpet {

private:
	Graphics^ gfx;
	void recurse(Rectangle rect, int n);
public:
	SierpinskiCarpet(Graphics^ startGraphics);
	void Draw(int depth);

};