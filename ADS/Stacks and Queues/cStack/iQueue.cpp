#include "StdAfx.h"
#include "iQueue.h"

iQueue::iQueue(void) {
	head = nullptr;
	tail = nullptr;
}

/*
 PRE: 
*/
void iQueue::Push(int n) {
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
void iQueue::PushRange(array<int>^ range) {
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
int iQueue::Pop() {
	int n = head->Value;
	deleteNode(head);
	return n;
}
/*
	POST: Top of stack has been returned and removed
*/

/*
	PRE: IsEmpty Must be called first
*/
int iQueue::Peek() {
	return head->Value;
}
/*
	POST: Top of stack has been returned without being removed
*/

/*
	PRE: Count must be called and return a lower value than index to be retireved
*/
int iQueue::IndexOf(int n) {
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
bool iQueue::IsEmpty() {
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
int iQueue::Count() {
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
void iQueue::addNode(Node^ newNode) {
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
	POST: iQueue Count + 1
*/

/*
	PRE: 
*/
void iQueue::deleteNode(Node^ dNode) {
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
	POST: iQueue Count - 1
*/