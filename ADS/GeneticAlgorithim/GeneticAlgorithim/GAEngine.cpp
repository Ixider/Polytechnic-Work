#include "stdafx.h"
#include "GAEngine.h"
#define BIT_L 10
GAEngine::GAEngine(ListBox^ display) {
	disp = display;

	rGen = gcnew Random();
	enviroment = gcnew PriorityQueue<array<int>^>();

	initilize();
}

void GAEngine::initilize() {
	for(int i = 0; i < populationMax; i++ ) {
		array<int>^ binarySequence = gcnew array<int>(BIT_L);

		for(int j = 0; j < binarySequence->Length; j++) 
			binarySequence[j] = rGen->Next(2);
		
		enviroment->Add(binarySequence, scoreSequence(binarySequence));
	}
}

String^ GAEngine::Run() {

	while(enviroment->Peek()->PriorityScore != 0) {
		CullTheWeak();
		selection();

		String^ str = enviroment->topToString();
		disp->Items->Add(str);
	}

	disp->Items->Add(enviroment->topToString());
	return "";
}

void GAEngine::selection() {
	int length = enviroment->Count();
	for(int i = 0; i < length; i += 2) {
		double prob = rGen->Next(1, 11) / 10.0;
		combine(enviroment->AtIndex(i), enviroment->AtIndex(i+1));
	}

	for(int i = 0; i < populationMax; i++) {
		enviroment->AtIndex(i)->PriorityScore = scoreSequence(enviroment->AtIndex(i)->Value);
	}
}

void GAEngine::combine(PQNODE<array<int>^>^ node1, PQNODE<array<int>^>^ node2) {
	int piviot = rGen->Next(node1->Value->Length);

	array<int>^ child1 = gcnew array<int>(10);
	array<int>^ child2 = gcnew array<int>(10);

	for(int i = 0; i < child1->Length; i++) {
		if(i < piviot) {
			child1[i] = node1->Value[i];
			child2[i] = node2->Value[i];
		}
		else {
			child1[i] = node2->Value[i];
			child2[i] = node1->Value[i];
		}
	}

	enviroment->Add(child1, scoreSequence(child1));
	enviroment->Add(child2, scoreSequence(child2));
}

void GAEngine::mutate(PQNODE<array<int>^>^ node) {

}

void GAEngine::Elitism() {

}

void GAEngine::CullTheWeak() {
	while(enviroment->Count() > (populationMax/2)) 
		enviroment->PopEnd();
}

int GAEngine::scoreSequence(array<int>^ squence) {
	int rank = 0;

	for each(int i in squence)
		if(i == 0)
			rank++;

	return rank;
}