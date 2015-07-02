#pragma once

using namespace::System;

ref class QuickSort {

private:
	void quickSort(int left, int right, array<int>^ a);
	void SwapItems(int firstIndex, int secondIndex, array<int>^ a);
public:
	array<int>^ Sort(array<int>^ a);

};
