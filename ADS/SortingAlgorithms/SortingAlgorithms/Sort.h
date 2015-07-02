#pragma once
#include "Statistics.h"

using namespace System;
using namespace System::Collections;


ref class Sort {
private:
	Statistics^ stats;
	int operationCount;
	int findMax(array<int>^ set, int lastIndex);
	void swapItems(array<int>^ set, int indexA, int indexB);
	void MergeArray(array<int>^ set, int lb1, int ub1, int lb2, int lb3);

public:
	Sort();
	Sort(Statistics^ stats){ this->stats = stats; }
	array<int>^ Merge(array<int>^ set);
	array<int>^ Bubble(array<int>^ set);
	array<int>^ Selection(array<int>^ set);
	array<int>^ Insertion(array<int>^ set);
};