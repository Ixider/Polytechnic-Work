#pragma once

using namespace System;

ref class StatsRecord {

public:
	int T;
	int H;
	int L;
	
	StatsRecord(int sT, int sH, int sL) {
		T = sT;
		H = sH;
		L = sL;
	}
};