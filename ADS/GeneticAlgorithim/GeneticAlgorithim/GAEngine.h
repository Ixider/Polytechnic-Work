#pragma once
#include "PriorityQueue.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

ref class GAEngine {
private:
	static const int populationMax = 8;
	ListBox^ disp;

	Random^ rGen;
	PriorityQueue<array<int>^>^ enviroment;

	void initilize();
	void selection();
	void combine(PQNODE<array<int>^>^ node1, PQNODE<array<int>^>^ node2);

	void mutate(PQNODE<array<int>^>^ node);
	void Elitism();

	void CullTheWeak();

	int scoreSequence(array<int>^ squence);

public:
	GAEngine(ListBox^ display);
	String^ Run();
};