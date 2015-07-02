#include "stdafx.h"
#include "Manager.h"

Manager::Manager() {
	
}

void Manager::RunSim(int H, int L, Decimal A, Decimal B, Decimal C, Decimal D) {
	sim = gcnew Simulation(H, L, A, B, C, D);

	sim->Run();
}