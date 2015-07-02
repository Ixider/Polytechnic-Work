#include "StdAfx.h"
#include "Sort.h"

Sort::Sort() {
	operationCount = 0;
}
// MERGE SORT
array<int>^ Sort::Merge(array<int>^ set) {
	operationCount = 0;

	int lb1;
	int lb2;

	//StatsCollection +1 group length assignment
	operationCount++;

	int groupLength = 1;
	while(groupLength < set->Length) {
		lb1 = 0;
		lb2 = groupLength;

		//StatsCollection +1 while loop comparison, +2 assignments of lower bounds, +1 for group length increment.
		operationCount += 4;

		while((lb2 + groupLength) <= set->Length) {
			MergeArray(set, lb1, lb1 + groupLength, lb2, lb2 + groupLength);
			lb1 = (lb2 + groupLength);
			lb2 = (lb1 + groupLength);

			//StatsCollection +2 for while loop addition and comparision, +2 for additions in method call, +4 for lower bounds addition and assignment 
			operationCount += 8;
		}

		groupLength *= 2;
	}

	//StatsCollection +1 for return
	operationCount++;


	//StatsCollection
	if(stats != nullptr)
		stats->WriteToFile(Convert::ToString(operationCount));

	return set;
}

void Sort::MergeArray(array<int>^ set, int lb1, int ub1, int lb2, int ub2) {
	//StatsCollection
	operationCount = 0;

	array<int>^ tempArray = gcnew array<int>((ub1 - lb1)* 2);
	int lowerBounds = lb1;
	int upperBounds = ub2;

	//StatsCollection
	operationCount += 6;

	int index = -1;
	for(int i = 0; i < tempArray->Length; i++) {

		//StatsCollection / +1 = for loop, +2 = comparisions in if statment
		operationCount += 3;
		if(lb1 < ub1 && lb2 < ub2) { // If one indices is at its lower bounds only items from one need to be added
			//StatsCollection / +1 if statment comparison
			operationCount++;
			if(set[lb1] < set[lb2]) 
			{
				tempArray[i] = set[lb1];
				lb1++;

				//StatsCollection / +1 for assignment of temp array +1 for increment of lower bounds
				operationCount += 2;
			} else {// add to temp array and move the lower bounds for that side of the array up
				tempArray[i] = set[lb2];
				lb2++;

				//StatsCollection / +1 for assignment of temp array +1 for increment of lower bounds
				operationCount += 2;
			}
		}
		else { // check which lower bound index is less than its upper bounds and fill rest of array from that
			//StatsCollection / +1 for ifstatment comparison +2 for contents of if and else
			operationCount += 3;
			if(lb1 < ub1) {
				tempArray[i] = set[lb1];
				lb1++;
			} else {
				tempArray[i] = set[lb2];
				lb2++;
			}		
		}


	}
	//StatsCollection / +1 assignemtn of count
	operationCount++;	

	// overwrite the set pointer with the sorted values
	int count = 0;
	for(int i = lowerBounds; i < upperBounds; i++) {
		set[i] = tempArray[count];
		count++;

		//StatsCollection / +1 for forloop, +1 assignment to set, +1 increment of count
		operationCount += 3;
	}
}
// END OF MERGE SORT


//BUBBLE SORT
// O(n sqr)
array<int>^ Sort::Bubble(array<int>^ set) {
	//StatsCollection
	operationCount = 0;


	//StatsCollection +1 for sortedIndex assignment
	operationCount++;

	int sortedIndex = set->Length - 1;
	for(int i = 0; i < set->Length; i++) {
		//StatsCollection +1 for loop, +1 deincrement
		operationCount += 2; 
		for(int j = 0; j < sortedIndex; j++) {
			//StatsCollection +1 for loop, +1 comparison, +1 addition
			operationCount += 3;
			if(set[j] > set[j + 1]) {
				//StatsCollection +3 for swap
				operationCount += 3;
				swapItems(set, j, j+1);
			}				
		}
		sortedIndex--;
	}

	//StatsCollection +1 return
	operationCount++;

	if(stats != nullptr)
		stats->WriteToFile(Convert::ToString(operationCount));

	return set;
}
//END OF BUBBLE

//SELECTION SORT
array<int>^ Sort::Selection(array<int>^ set) {
	//StatsCollection
	operationCount = 0;

	//StatsCollection +1 n assignment
	operationCount++;

	int n = set->Length - 1;
	while(n > 0) {
		//StatsCollection +1 while comparison +3 swap operations, +1 for n deincrement
		operationCount += 4;		
		int max = findMax(set, n);
		swapItems(set, max, n);
		n--;
	}

	if(stats != nullptr)
		stats->WriteToFile(Convert::ToString(operationCount));

	return set;
}

/*
	O(n) operation
	Will find the max in a subset of the given array

	PRE:
*/
int Sort::findMax(array<int>^ set, int lastIndex) {
	int index = 0;
	int max = 0;

	// StatsCollection +2 for assignemnt of max and index
	operationCount += 2;

	for(int i = 0; i <= lastIndex; i++) {
		// StatsCollection +1 for loop, +1 for comparison
		operationCount += 2;
		if(set[i] > max) {
			// StatsCollection +2 for assignemnt of max and index
			operationCount += 2;
			max = set[i];
			index = i;
		}
	}
	// StatsCollection +1 for return
	operationCount++;

	return index;
}
/*
	POST: 
*/
// END OF SELECTION SORT


//INSERTION SORT
// im feeling O(n)?
array<int>^ Sort::Insertion(array<int>^ set) {
	operationCount = 0;

	for(int i = 0; i < set->Length; i++) {
		// StatsCollection +1 for loop, +3 for assignments
		operationCount += 4;

		int item = set[i];
		int insertIndex = 0;
		for(int x = i; x >= 0; x--) {
			// StatsCollection +1 for loop, +2 for comparisions
			operationCount += 3;

			if(set[x] > item) {
				// StatsCollection +1 for addition, +1 for assignment
				operationCount += 2;
				set[x + 1] = set[x];
			} else if (set[x] < item) {
				// StatsCollection +1 for addition, +1 for assignment
				operationCount += 2;

				insertIndex = (x + 1);
				break;
			}
		}
		set[insertIndex] = item;
	}

	// StatsCollection +1 for return
	operationCount++;

	if(stats != nullptr)
		stats->WriteToFile(Convert::ToString(operationCount));

	return set;
}
//END OF INSERTION


// METHODS USED BY MULTIPLE SORTS
/*
	Swap items will swap the items at each index in a given set

	PRE: 
*/
void Sort::swapItems(array<int>^ set, int indexA, int indexB) {
	int temp = set[indexA];
	set[indexA] = set[indexB];
	set[indexB] = temp;
}
/*
	POST: 
*/


