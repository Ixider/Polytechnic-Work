#pragma once
#include "BinarySearchTree.h"

using namespace::System;
using namespace::System::Windows::Forms;

ref class Manager {
private:
	BinarySearchTree^ bst;
	ListBox^ listBox;

	BinarySearchTree^ constructBST();
public:
	Manager(ListBox^ lb);
	String^ search(int i);
	
	void randomizeBST();
};