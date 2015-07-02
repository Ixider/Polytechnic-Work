#include "StdAfx.h"
#include "iStack.h"

iStack::iStack(void)
{
	head = nullptr;
	tail = nullptr;
}

/*
 PRE: 
*/
void iStack::Push(int n) {
	Node^ node = gcnew Node();
	node->Value = n;
	addNode(node);
}
/*
	POST: New value has been added to the stack
*/

/*
	PRE: 
*/
void iStack::PushRange(array<int>^ range) {
	for each(int n in range) {
		Node^ node = gcnew Node();
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
int iStack::Pop() {
	int n = tail->Value;
	deleteNode(tail);
	return n;
}
/*
	POST: Top of stack has been returned and removed
*/

/*
	PRE: IsEmpty Must be called first
*/
int iStack::Peek() {
	return tail->Value;
}
/*
	POST: Top of stack has been returned without being removed
*/

/*
	PRE: Count must be called and return a lower value than index to be retireved
*/
int iStack::IndexOf(int n) {
	Node^ tNode = head;

	int count = 0;
	while(count != n) {
		count++;
		tNode = tNode->Next;
	}

	return tNode->Value;
}


/*
	PRE: 
*/
bool iStack::IsEmpty() {
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
int iStack::Count() {
	Node^ tNode = head;

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
void iStack::addNode(Node^ newNode) {
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
	POST: iStack Count + 1
*/

/*
	PRE: 
*/
void iStack::deleteNode(Node^ dNode) {
	Node^ tNode = head; // tNode = traverseNode // dNode = deleteNode

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
	POST: iStack Count - 1
*/