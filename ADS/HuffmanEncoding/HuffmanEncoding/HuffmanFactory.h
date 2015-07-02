#pragma once
#include "PriorityStack.h"
#include "BinarySearchTree.h"

using namespace::System;

ref class HuffmanFactory {
private:
	BinarySearchTree^ constructTree(PriorityStack<BinarySearchTree^>^ ps);
	PriorityStack<BinarySearchTree^>^ createQueue(array<int>^ charCounts);
	array<int>^ countOccurances(String^ string);

public:
	BinarySearchTree^ ConstructHuffmanTree(List<String^>^ symbols, List<int>^ frequencies);
	BinarySearchTree^ ConstructHuffmanTree(String^ input);
};
