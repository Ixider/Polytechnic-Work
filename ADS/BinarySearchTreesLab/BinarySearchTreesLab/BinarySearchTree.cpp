#include "stdafx.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {

}

//Public
void BinarySearchTree::Add(int i) {
	insertItem(rootNode, i);
}

bool BinarySearchTree::Contains(int i) {
	return findItem(rootNode, i);
}

//Priavte
void BinarySearchTree::insertItem(Node<int>^ %node, int value) {
	
	// Leaf Condition
	if(node == nullptr) {
		node = gcnew Node<int>(value);
		return;
	}

	// Tree Navigation
	if(value < node->Value) {
		return insertItem(node->Left, value);
	}

	return insertItem(node->Right, value);		
}

bool BinarySearchTree::findItem(Node<int>^ node, int targetValue) {
	// Item not found case
	if(node == nullptr) {
		return false;
	}

	// Item found condition
	if(targetValue == node->Value) {
		return true;
	}

	// Tree Navigation
	if(targetValue < node->Value) {
		return findItem(node->Left, targetValue);
	}	
	return findItem(node->Right, targetValue); 
}