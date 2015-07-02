#include "stdafx.h"
#include "Simulation.h"

#define REPOP_CONST 2.718
Simulation::Simulation(int Hares, int Lynx, Decimal HBirthRate, Decimal LDeathRate, Decimal LRepoductionEffeciency, Decimal Predation) {
	H = Hares;
	L = Lynx;

	A = HBirthRate;
	B = Predation;
	C = LRepoductionEffeciency;
	D = LDeathRate;

	T = 0;
	history = gcnew List<StatsRecord^>();
}

List<StatsRecord^>^ Simulation::Run() {
	if(H < 0 || L < 0) {
		return history;
	}
	else {
		record();
		incrementTime();		
		calculateHarePopulation();
		calculateLynxPopulation();

		H = H1;
		L = L1;

		Run();
	}
}

void Simulation::calculateHarePopulation() {
	H1 = (int)(H + A*H - B*H*L);
}

void Simulation::calculateLynxPopulation() {
	L1 =  (int)(L + C*L*H - D*L);
}

void Simulation::incrementTime() {
	T++;
}

void Simulation::record() {
	history->Add(gcnew StatsRecord(T, H, L));
}
