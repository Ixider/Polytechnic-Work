#pragma once
#include "BinaryTree.h"

using namespace::System;
using namespace::System::Collections::Generic;

ref class BinarySearchTree : BinaryTree<int> {

private:
	void insertItem(Node<int>^ %rootNode, int value, String^ symbol);
	void encodeTree(Node<int>^ node, String^ code);

public:
	Dictionary<String^, String^>^ CodeStore;
	String^ encodedString;
	String^ decodeString(String^ str);
	void Add(int i, String^ s);
	void generateCodes();;
};