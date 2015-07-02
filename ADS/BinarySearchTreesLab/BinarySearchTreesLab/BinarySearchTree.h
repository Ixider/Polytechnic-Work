#pragma once
#include "BinaryTree.h"

using namespace::System;

ref class BinarySearchTree : BinaryTree<int> {

private:
	void insertItem(Node<int>^ %rootNode, int value);
	bool findItem(Node<int>^ inputRootNode, int targetValue);

public:
	BinarySearchTree();
	void Add(int i);
	bool Contains(int i);

};