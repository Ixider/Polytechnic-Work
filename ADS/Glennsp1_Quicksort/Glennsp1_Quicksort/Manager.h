#pragma once
#include "QuickSort.h"

using namespace::System;
using namespace::System::Windows::Forms;

ref class Manager {

private:
	static int MAX_INTS = 512;

	Random^ rGen;
	QuickSort^ quickSort;

	ListBox^ s;
	ListBox^ us;

	array<int>^ populate();	

public:
	Manager(ListBox^ unsorted, ListBox^ sorted);
	void run();


};