#pragma once
#include "StatsRecord.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Simulation {
private:
	Graphics^ gfx;
	List<StatsRecord^>^ history;

	int T;

	int H;
	int L;

	int H1;
	int L1;

	Decimal A;	
	Decimal B;
	Decimal C;
	Decimal D;

	void calculateLynxPopulation();
	void calculateHarePopulation();
	void incrementTime();

	void record();

	

public:
	Simulation(int Hares, int Lynx, Decimal HBirthRate, Decimal LDeathRate, Decimal LMaxPop, Decimal HEatenProb);
	List<StatsRecord^>^ Run();
};