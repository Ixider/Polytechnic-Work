#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

#define nodeWidth 50
#define offSetModifier 30
//NODE CLASS
template <class NT>
ref class Node {
private:
public:
	Node(NT startValue, String^ symbol) { 
		Value = startValue; 
		Symbol = symbol;
	}
	NT Value;
	String^ Symbol;
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
	bool isEmpty() { if(rootNode == nullptr) { return true; } }
	
	// Data setting and retival 
	Node<T>^ getRootNode() { return rootNode; }
	T getRootNodeValue() { 	return rootNode->Value; }
	String^ getRootNodeSymbol() { return rootNode->Symbol; }
	void setRootNodeValue(T value) { rootNode->Value = value; }

	// Construction
	void makeLeftChildNode(T value, String^ symbol) { rootNode->Left = gcnew Node<T>(value, symbol); }
	void makeRightChildNode(T value, String^ symbol) { rootNode->Right = gcnew Node<T>(value, symbol); }

	void addLeftSubTree(BinaryTree^ newTree) { rootNode->Left = newTree->getRootNode(); }
	void addRightSubTree(BinaryTree^ newTree) { rootNode->Right = newTree->getRootNode(); }

	void drawTree(Graphics^ gfx);
	void recurseDraw(Graphics^ gfx, int startX, int startY, int currentOffset, Node<T>^ node);
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

template<class T>
void BinaryTree<T>::drawTree(Graphics^ graphics) {
	graphics->Clear(Color::White);
	recurseDraw(graphics, 500, 0, 175, rootNode);
}

#define nodeWidth 50
#define offSetModifier 30

template<class T>
void BinaryTree<T>::recurseDraw(Graphics^ gfx, int startX, int startY, int currentOffset, Node<T>^ node) {
	gfx->DrawEllipse(gcnew Pen(Color::Black), startX, startY, nodeWidth, nodeWidth);
	gfx->DrawString(node->Symbol + " " + Convert::ToString(node->Value),
					gcnew Font("Arial", 12),
					gcnew SolidBrush(Color::Black),
					startX + 3, startY + 3);

	if(node->Left != nullptr) {
		gfx->DrawLine(gcnew Pen(Color::Black), startX, startY, startX - currentOffset, startY + nodeWidth);
		recurseDraw(gfx, startX - currentOffset, startY + nodeWidth, currentOffset -= offSetModifier, node->Left);
	}

	if(node->Right != nullptr) {
		gfx->DrawLine(gcnew Pen(Color::Black), startX + nodeWidth, startY, startX + currentOffset + nodeWidth, startY + nodeWidth);
		recurseDraw(gfx, startX + currentOffset, startY + nodeWidth, currentOffset -= offSetModifier, node->Right);
	}
}