#pragma once

using namespace System;

ref class Node {
public:
	Node(int value) {
	   Value = value;
	}

	int Value;
	Node^ Next;
};

ref class LinkedList
{
private:
	Node^ head;
	Node^ tail;
	void addNode(Node^ newNode);
	void deleteNode(Node^ stackTop);
	void reverseRecurse(Node^ currentNode);


public:
	LinkedList(void);

	void Push(int n);
	int Pop();
	int Peek();

	int Count();	
	bool IsEmpty();
	
	void RReverse();
	void IReverse();

	void Clear();

	array<String^>^ toStringArray();


};
