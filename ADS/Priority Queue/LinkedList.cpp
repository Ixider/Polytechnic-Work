#include "StdAfx.h"
#include "LinkedList.h"

LinkedList::LinkedList(void)
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList::Push(int n) {
	Node^ index = gcnew Node(n);
	addNode(index);
}

int LinkedList::Pop() {
	int n = head->Value;
	deleteNode(head);
	return n;
}

int LinkedList::Peek() {

}


/*
	PRE: 
*/
void LinkedList::addNode(Node^ newNode) {
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
	POST: 
*/

/*
	PRE: 
*/
void LinkedList::deleteNode(Node^ dNode) {
	Node^ tNode = head;

	if(dNode == head) {
		if(tNode->Next == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = tNode->Next;
		}
	}
	else
	{
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
	POST: 
*/


/*
	PRE: 
*/
bool LinkedList::IsEmpty() {
	return false;
}
/*
	PRE: 
*/


/*
	PRE: 
*/
int LinkedList::Count() {
	Pellet^ nodeWalker = head;

	int count = 0;
	while(nodeWalker != nullptr) {
		count++;
		nodeWalker = nodeWalker->Next;
	}

	return count;
}
/*
	POST: 
*/