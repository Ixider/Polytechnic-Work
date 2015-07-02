#include "stdafx.h"
#include "Manager.h"

#define MAX 10

Manager::Manager(ListBox^ lb) {
	displayBox = lb;
	linkedList = gcnew LinkedList();
}

void Manager::Populate() {
	linkedList->Clear();

	for(int i = 0; i < MAX; i++) {
		linkedList->Push(i);
	}

	Display();
}

void Manager::Reverse() {
	linkedList->RReverse();
	Display();
}

void Manager::Display() {
	displayBox->Items->Clear();
	displayBox->Items->AddRange(linkedList->toStringArray());
}