#include "StdAfx.h"
#include "ArrayFactory.h"

ArrayFactory::ArrayFactory() {
	rGen = gcnew Random();
}

/*
	PRE: Integer supplied must be a maximum of 12
*/
array<int>^ ArrayFactory::MakeArray(int setSize) {
	int size = Math::Pow(2, setSize);

	array<int>^ newSet = gcnew array<int>(size);

	PopulateArray(newSet);

	return newSet; 
}
/*
	POST: Returns new array with length of 2^pwr of input 
*/

/*
	PRE: 
*/
void ArrayFactory::PopulateArray(array<int>^ newSet) {
	for(int i = 0; i < newSet->Length; i++)
		newSet[i] = rGen->Next(1000);
}
/*
	POST: Array filled with random Integers
*/