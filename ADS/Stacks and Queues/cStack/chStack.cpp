#include "StdAfx.h"
#include "chStack.h"

chStack::chStack(void)
{
	head = nullptr;
	tail = nullptr;
}

/*
 PRE: 
*/
void chStack::Push(char n) {
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
void chStack::PushRange(array<char>^ range) {
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
char chStack::Pop() {
	char n = tail->cValue;
	deleteNode(tail);
	return n;
}
/*
	POST: Top of stack has been returned and removed
*/

/*
	PRE: IsEmpty Must be called first
*/
char chStack::Peek() {
	return tail->cValue;
}
/*
	POST: Top of stack has been returned without being removed
*/

/*
	PRE: Count must be called and return a lower value than index to be retireved
*/
char chStack::IndexOf(int n) {
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
bool chStack::IsEmpty() {
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
int chStack::Count() {
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
void chStack::addNode(cNode^ newNode) {
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
	POST: chStack Count + 1
*/

/*
	PRE: 
*/
void chStack::deleteNode(cNode^ dNode) {
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
	POST: chStack Count - 1
*/