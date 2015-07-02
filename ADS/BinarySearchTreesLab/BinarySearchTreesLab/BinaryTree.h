#pragma once

using namespace System;
using namespace System::Windows::Forms;

//NODE CLASS
template <class NT>
ref class Node {
private:
public:
	Node(NT startValue) { Value = startValue; }
	NT Value;
	Node<NT>^ Left;
	Node<NT>^ Right;
};


// BINARY TREE CLASS
template <class T>
ref class BinaryTree {
protected:
	Node<T>^ rootNode;

private:
public:
	BinaryTree() {}
	BinaryTree(T rootValue) { rootNode = gcnew Node<T>(rootValue); }
	BinaryTree(T rootvalue, BinaryTree^ leftTree, BinaryTree^ rightTree) {
		rooNode = gcnew Node<T>(rootValue);
		rooNode->Left = leftTree->getRootNode();
		rooNode->Right = rightTree->getRootNode();
	}

	//Traversal
	void postOrder(Node<T>^ inputRootNode, ListBox^ targetListBox);
	void preOrder(Node<T>^ inputRootNode, ListBox^ targetListBox);
	void inOrder(Node<T>^ inputRootNode, ListBox^ targetListBox);

	// state checking
	bool isEmpty() { if(rooNode == nullptr) { return true; } }
	
	// Data setting and retival 
	Node<T>^ getRootNode() { return rootNode; }
	T getRooNodeValue() { 	return rooNode->Value; }
	void setRooNodeValue(T value) { rooNode->Value = value; }

	// Construction
	void makeLeftChildNode(T value) { rootNode->Left = gcnew Node<T>(value); }
	void makeRightChildNode(T value) { rootNode->Right = gcnew Node<T>(value); }

	void addLeftSubTree(BinaryTree^ newTree) { rootNode->Left = newTree->getRootNode(); }
	void addRightSubTree(BinaryTree^ newTree) { rootNode->Right = newTree->getRootNode(); }
};

template<class T>
void BinaryTree<T>::postOrder(Node<T>^ inputRootNode, System::Windows::Forms::ListBox^ targetListBox) {
	if(inputRootNode != nullptr) {
		postOrder(inputRootNode->Left, targetListBox);

		postOrder(inputRootNode->Right, targetListBox);

		targetListBox->Items->Add(Convert::ToString(inputRootNode->Value));
	}
}

template<class T>
void BinaryTree<T>::preOrder(Node<T> ^inputRootNode, System::Windows::Forms::ListBox ^targetListBox) {
	if(inputRootNode != nullptr) {
		targetListBox->Items->Add(Convert::ToString(inputRootNode->Value));

		preOrder(inputRootNode->Left, targetListBox);

		preOrder(inputRootNode->Right, targetListBox);
	}
}

template<class T>
void BinaryTree<T>::inOrder(Node<T> ^inputRootNode, System::Windows::Forms::ListBox ^targetListBox) {
	if(inputRootNode != nullptr) {
		inOrder(inputRootNode->Left, targetListBox);

		targetListBox->Items->Add(Convert::ToString(inputRootNode->Value));

		inOrder(inputRootNode->Right, targetListBox);
	}
}
