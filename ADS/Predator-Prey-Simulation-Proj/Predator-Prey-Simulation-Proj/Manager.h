#pragma once
#include "Simulation.h"

using namespace::System;
using namespace::System::Drawing;

ref class Manager {
private:
	Graphics^ gfx;

	Simulation^ sim;
	
public:
	Manager();
	void RunSim(int H, int L, Decimal A, Decimal B, Decimal C, Decimal D);
};