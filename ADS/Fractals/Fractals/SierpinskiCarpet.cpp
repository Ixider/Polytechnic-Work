#include "stdafx.h"
#include "SierpinskiCarpet.h"

#define DEPTH 6

SierpinskiCarpet::SierpinskiCarpet(Graphics^ startGraphics) {
	gfx = startGraphics;
}

void SierpinskiCarpet::recurse(Rectangle r, int n) {
	if(n > 0) {
		n--;
		Rectangle x = r;
		Pen^ p = gcnew Pen(Color::Black);
		int side = r.Width/3;

		gfx->DrawRectangle(p, r.Left, r.Top, r.Width, r.Height);

		int left = r.Left + side;
		int left2 = r.Left + side*2;
		// Draws vertial Lines
		gfx->DrawLine(p, left, r.Top, left, r.Bottom);   
		gfx->DrawLine(p, left2, r.Top, left2, r.Bottom); 

		//Draws horizontal lines
		gfx->DrawLine(p, r.Left, r.Top + side, r.Right, r.Top + side );   
		gfx->DrawLine(p, r.Left, r.Top + side*2, r.Right, r.Top + side*2 );

		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++) {
				if(i != 1 || j != 1) {
					recurse(Rectangle(r.Left + (side * i), r.Top + (side * j), side, side), n);				
				}
			}
		}
	}
}

void SierpinskiCarpet::Draw(int depth) {
	Rectangle rect = Rectangle(50, 50, 630, 630);
	recurse(rect, depth);
}

