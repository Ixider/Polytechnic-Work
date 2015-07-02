#include "stdafx.h"
#include "Manager.h"


Manager::Manager(ListBox^ unsorted, ListBox^ sorted) {
	s = sorted;
	us = unsorted;

	rGen = gcnew Random();
	quickSort = gcnew QuickSort();
}


void Manager::run() {
	array<int>^ unsorted = populate();
	
	for each(int i in unsorted) 
		us->Items->Add(Convert::ToString(i));

	for each(int i in quickSort->Sort(unsorted))
		s->Items->Add(Convert::ToString(i));
	
}

array<int>^ Manager::populate() {
	array<int>^ ia = gcnew array<int>(MAX_INTS);
	
	for(int i = 0; i < ia->Length; i++)
		ia[i] = rGen->Next(0, 999);

	return ia;
}