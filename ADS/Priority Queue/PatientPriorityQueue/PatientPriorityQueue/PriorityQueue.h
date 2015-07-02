#pragma once
#include "Patient.h";

using namespace System;
using namespace System::Collections;

ref class PriorityQueue
{
private:
	array<Patient^>^ queue;

	void shiftDown();
	void QuickSort();
	void QuickSort(int left, int right);
	void SwapItems(int indexOne, int indexTwo);
	int Partition(int left, int right);
	int getIndexOfLastElement();



public:
	PriorityQueue(void);

	void insert(Patient^ p);
	Patient^ pop();
	Patient^ peek();
	bool IsFull();
	bool IsEmpty();
	bool Contains(int priorityScore);

	array<String^>^ toString();
};

