#pragma once
#include "Sort.h"
#include "ArrayFactory.h"
#include "Statistics.h"

using namespace System;
using namespace System::Collections;

public enum SortType { MERGE, BUBBLE, SELECTION, INSERTION };

ref class Manager {
private:
	Sort^ sort;
	ArrayFactory^ af;
	String^ arrayToString(array<int>^ a);
	delegate array<int>^ SortMethod(array<int>^ set);
	SortMethod^ sortMethod;

	void RunTest(SortMethod^ sortMethod, Statistics^ stats);

public:
	Manager();
	void RunTests(String^ fileName);
	void setSortType(SortType sortType);
	array<String^>^ runSort(int setSizeModifier);

};

