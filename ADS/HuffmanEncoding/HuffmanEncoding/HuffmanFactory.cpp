#include "stdafx.h"
#include "HuffmanFactory.h"


/*
	Method chain constructs huffman tree from an array of symbols and array of frequencies
	PRE:
*/
BinarySearchTree^ HuffmanFactory::ConstructHuffmanTree(List<String^>^ symbols, List<int>^ frequencies) {

	PriorityStack<BinarySearchTree^>^ ps = gcnew PriorityStack<BinarySearchTree^>();
	
	for(int i = 0; i < symbols->Count; i++) {
		BinarySearchTree^ newT = gcnew BinarySearchTree();
		newT->Add(frequencies[i], symbols[i]);
		ps->insert(newT, frequencies[i]);
	}

	return constructTree(ps);
}


/*
	Method chain constructs huffman tree from a given string
	PRE:
*/

BinarySearchTree^ HuffmanFactory::ConstructHuffmanTree(String^ input) {
	PriorityStack<BinarySearchTree^>^ pq = createQueue(countOccurances(input));

	BinarySearchTree^ huffmanTree = constructTree(pq);

	return huffmanTree;
}



BinarySearchTree^ HuffmanFactory::constructTree(PriorityStack<BinarySearchTree^>^ ps) {

	while(ps->Count() > 1) {
		BinarySearchTree^ one = ps->Pop()->Value;
		BinarySearchTree^ two = ps->Pop()->Value;

		Node<int>^ node = one->getRootNode();
		String^ newString = one->getRootNodeSymbol() + two->getRootNodeSymbol();
		int newFrequencey = one->getRootNodeValue() + two->getRootNodeValue();

		BinarySearchTree^ newT = gcnew BinarySearchTree();
		newT->Add(newFrequencey, newString);
		newT->addLeftSubTree(one);
		newT->addRightSubTree(two);

		ps->insert(newT, newFrequencey);
	}

	BinarySearchTree^ huffmanTree = ps->Pop()->Value;

	return huffmanTree;
}

/*
	PRE: Count Occurances must called on a string and provided as input
*/
PriorityStack<BinarySearchTree^>^ HuffmanFactory::createQueue(array<int>^ charCounts) {
	PriorityStack<BinarySearchTree^>^ pq = gcnew PriorityStack<BinarySearchTree^>();

	for(int i = 0; i < charCounts->Length; i++) {
		if(charCounts[i] > 0) {
			BinarySearchTree^ ht = gcnew BinarySearchTree();
			ht->Add(charCounts[i], Convert::ToString(Convert::ToChar(i)));
			pq->insert(ht, ht->getRootNodeValue());	
		}
	}

	return pq;
}
/*
	POST: A prioiry queue is returned in sorted order of their frequencies 
*/

/*
	PRE: 
*/
array<int>^ HuffmanFactory::countOccurances(String^ string) {
	array<int>^ counts = gcnew array<int>(256);

	for each(char c in string) 
		counts[(int)c]++;

	return counts;
}
/*
	POST:
*/