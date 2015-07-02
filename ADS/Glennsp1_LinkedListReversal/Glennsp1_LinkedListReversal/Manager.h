#pragma once
#include "LinkedList.h"

using namespace System;
using namespace System::Windows::Forms;

ref class Manager {
private:
	LinkedList^ linkedList;
	ListBox^ displayBox;

public:
	Manager(ListBox^ lb);
	void Display();
	void Reverse();
	void Populate();
};