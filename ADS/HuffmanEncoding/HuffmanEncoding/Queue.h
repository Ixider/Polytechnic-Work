#pragma once

using namespace System;

template <class NT>
ref class cNode
{
private:
public:
	cNode(NT sValue) { Value = sValue; }
	NT Value;
	cNode<NT>^ Next;
};

template <class T>
ref class Queue
{
private:
	cNode<T>^ head;
	cNode<T>^ tail;
	void addNode(cNode<T>^ newNode);
	void deleteNode(cNode<T>^ stackTop);


public:
	Queue() {
		head = nullptr;
		tail = nullptr;	
	}

	void Push(T n);
	T Peek();
	T Pop();
	void PushRange(array<T>^ range);
	int Count();	
	bool IsEmpty();
};

/*
 PRE: 
*/
template<class T>
void Queue<T>::Push(T n) {
	cNode<T>^ node = gcnew cNode<T>(n);
	addNode(node);
}
/*
	POST: New value has been added to the stack
*/

/*
	PRE: 
*/
template<class T>
void Queue<T>::PushRange(array<T>^ range) {
	for each(char n in range) {
		cNode<T>^ node = gcnew cNode();
		node->Value = n;
		addNode(node);
	}
}

/*
	POST:
*/

/*
	PRE: IsEmpty Must be called first
*/
template<class T>
T Queue<T>::Pop() {
	T n = head->cValue;
	deleteNode(tail);
	return n;
}
/*
	POST: Top of stack has been returned and removed
*/

/*
	PRE: IsEmpty Must be called first
*/
template<class T>
T Queue<T>::Peek() {
	return head->Value;
}
/*
	POST: Top of stack has been returned without being removed
*/

/*
	PRE: 
*/
template<class T>
bool Queue<T>::IsEmpty() {
	if(head == nullptr)
		return true;

	return false;
}
/*
	PRE: 
*/

/*
	PRE: 
*/
template<class T>
int Queue<T>::Count() {
	cNode<T>^ tNode = head;

	int count = 0;
	while(tNode != nullptr) {
		count++;
		tNode = tNode->Next;
	}

	return count;
}
/*
	POST: 
*/


// PRIVATE FUNCTIONS
/*
	PRE: Value at index has been returned without being removed
*/
template<class T>
void Queue<T>::addNode(cNode<T>^ newNode) {
	if(head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->Next = newNode;
		tail = newNode;
	}
}
/*
	POST: Queue Count + 1
*/

/*
	PRE: 
*/
template<class T>
void Queue<T>::deleteNode(cNode<T>^ dNode) {
	cNode<T>^ tNode = head; // tNode = traverseNode // dNode = deleteNode

	if(dNode == head) { 
		if(tNode->Next == nullptr) { 
			head = nullptr; // 
			tail = nullptr;
		}
		else {
			head = tNode->Next;
		}
	}
	else {
		while(tNode->Next != dNode) {
			tNode = tNode->Next;	
		}
		if(tNode->Next == tail) {
			tail = tNode;
		}
		tNode->Next = dNode->Next;
	}
        
	delete(tNode->Next);
}
/*
	POST: Queue Count - 1
*/