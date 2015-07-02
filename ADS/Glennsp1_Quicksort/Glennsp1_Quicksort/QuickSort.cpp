#include "stdafx.h"
#include "QuickSort.h"

array<int>^ QuickSort::Sort(array<int>^ a)
{
	quickSort(0, a->Length - 1, a);
	return a;
}
/*
	POST: 
*/

/*
	PRE:
*/
void QuickSort::quickSort(int left, int right, array<int>^ a)
{
	int i = left;
	int j = right;

	int pivot = a[(left + right) /2];

    while (i <= j) {
		while (a[i] < pivot) {
			i++;
		} 
        
		while (a[j] > pivot) {	
			j--;
		} 

		// Swaps place of the two items
		if (i <= j) {
			SwapItems(i, j, a);
			i++;
			j--;
		}
    }

	if(left < j)
		quickSort(left, j, a);
	if(i < right)
		quickSort(i, right, a);
}

void QuickSort::SwapItems(int firstIndex, int secondIndex, array<int>^ a) {	
	int temp = a[firstIndex];
	a[firstIndex] = a[secondIndex];
	a[secondIndex] = temp;
}