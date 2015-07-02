#include "StdAfx.h"
#include "Manager.h"


Manager::Manager() {

	sort = gcnew Sort();
	af = gcnew ArrayFactory();
	// Sets default sort method
	sortMethod = gcnew SortMethod(sort, &Sort::Selection);
}

array<String^>^ Manager::runSort(int setSizeModifier) {
	array<int>^ originalSet = af->MakeArray(setSizeModifier);
	String^ orginalSetStr = arrayToString(originalSet);

	array<int>^ sortedSet   = sortMethod(originalSet);
	String^ sortedSetStr = arrayToString(sortedSet);

	array<String^>^ result = { orginalSetStr, sortedSetStr };
	return result;
}

void Manager::RunTests(String^ fileName) {
	Statistics^ stats = gcnew Statistics();
	Sort^ sorter = gcnew Sort(stats);
	stats->OpenFile(fileName);

	stats->WriteToFile("Bubble Sort");
	SortMethod^ bubble = gcnew SortMethod(sorter, &Sort::Bubble);
	RunTest(bubble, stats);

	stats->WriteToFile("Insertion Sort");
	SortMethod^ insert = gcnew SortMethod(sorter, &Sort::Insertion);
	RunTest(insert, stats);

	stats->WriteToFile("Merge Sort");
	SortMethod^ merge = gcnew SortMethod(sorter, &Sort::Merge);
	RunTest(merge, stats);

	stats->WriteToFile("Selection Sort");
	SortMethod^ selection = gcnew SortMethod(sorter, &Sort::Selection);
	RunTest(selection, stats);

	stats->CloseFile();
}

void Manager::RunTest(SortMethod^ sortMethod, Statistics^ stats) {
	array<int>^ setModifiers = { 5, 6, 7, 8, 10, 11, 12 };
	for(int j = 0; j < setModifiers->Length; j++) {
		sortMethod(af->MakeArray(setModifiers[j]));
	}	
}

void Manager::setSortType(SortType sortType) {
	switch(sortType) {
		case SortType::MERGE:
			sortMethod = gcnew SortMethod(sort, &Sort::Merge);
			break;
		case SortType::BUBBLE:
			sortMethod = gcnew SortMethod(sort, &Sort::Bubble);
			break;
		case SortType::SELECTION:
			sortMethod = gcnew SortMethod(sort, &Sort::Selection);
			break;
		case SortType::INSERTION:
			sortMethod = gcnew SortMethod(sort, &Sort::Insertion);
			break;
	}
}

String^ Manager::arrayToString(array<int>^ a) {
	String^ result = "";
	for(int i = 0; i < a->Length; i++) {
		result += ("{0}", a[i].ToString()) + ", ";
	}
	return result;
}
