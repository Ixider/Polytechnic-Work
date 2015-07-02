#include "StdAfx.h"
#include "chQueue.h"

chQueue::chQueue(void)
{
	head = nullptr;
	tail = nullptr;
}

/*
 PRE: 
*/
void chQueue::Push(char n) {
	cNode^ node = gcnew cNode();
	node->cValue = n;
	addNode(node);
}
/*
	POST: New value has been added to the stack
*/

/*
	PRE: 
*/
void chQueue::PushRange(array<char>^ range) {
	for each(char n in range) {
		cNode^ node = gcnew cNode();
		node->cValue = n;
		addNode(node);
	}

}
/*
	POST:
*/

/*
	PRE: IsEmpty Must be called first
*/
char chQueue::Pop() {
	char n = head->cValue;
	deleteNode(tail);
	return n;
}
/*
	POST: Top of stack has been returned and removed
*/

/*
	PRE: IsEmpty Must be called first
*/
char chQueue::Peek() {
	return head->cValue;
}
/*
	POST: Top of stack has been returned without being removed
*/

/*
	PRE: Count must be called and return a lower value than index to be retireved
*/
char chQueue::IndexOf(int n) {
	cNode^ tNode = head;

	char count = 0;
	while(count != n) {
		count++;
		tNode = tNode->Next;
	}

	return tNode->cValue;
}


/*
	PRE: 
*/
bool chQueue::IsEmpty() {
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
int chQueue::Count() {
	cNode^ tNode = head;

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
void chQueue::addNode(cNode^ newNode) {
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
	POST: chQueue Count + 1
*/

/*
	PRE: 
*/
void chQueue::deleteNode(cNode^ dNode) {
	cNode^ tNode = head; // tNode = traverseNode // dNode = deleteNode

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
	POST: chQueue Count - 1
*/