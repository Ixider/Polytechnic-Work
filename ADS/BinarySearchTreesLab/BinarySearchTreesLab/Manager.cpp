#include "stdafx.h"
#include "Manager.h"

Manager::Manager(ListBox^ lb){
	listBox = lb;
	bst = constructBST();
}

BinarySearchTree^ Manager::constructBST(){
	BinarySearchTree^ bst = gcnew BinarySearchTree();

	bst->Add(20);
	bst->Add(37);
	bst->Add(16);
	bst->Add(18);
	bst->Add(7);
	bst->Add(43);
	bst->Add(38);
	bst->Add(4);


	////should return true;
	//bool result = bst->Contains(18);
	////Should return false
	//bool result2 = bst->Contains(100);

	bst->inOrder(bst->getRootNode(), listBox);
	return bst;
}

void Manager::randomizeBST() { 
	Random^ rGen = gcnew Random();
	for(int i = 0; i < 32; i++) {
		bst->Add(rGen->Next(100));
	}
}

String^ Manager::search(int i) {
	return "";
}