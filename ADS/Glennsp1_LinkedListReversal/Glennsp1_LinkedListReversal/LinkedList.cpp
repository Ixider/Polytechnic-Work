#include "StdAfx.h"
#include "LinkedList.h"

LinkedList::LinkedList(void)
{
	head = nullptr;
	tail = nullptr;
}

/* PRE: */
void LinkedList::Push(int n) {
	Node^ node = gcnew Node(n);
	addNode(node);
}
/* POST: */

/* PRE:  isEmpty must be called and return false value */
int LinkedList::Pop() {
	int n = head->Value;
	deleteNode(head);
	return n;
}
/* POST: */

/* PRE: */
int LinkedList::Peek() {
	return head->Value;
}
/* POST: */

/* PRE: */
int LinkedList::Count() {
	Node^ tNode = head;

	int count = 0;
	while(tNode != nullptr) {
		count++;
		tNode = tNode->Next;
	}

	return count;
}
/* POST: */

/* PRE: */
bool LinkedList::IsEmpty() {
	return false;
}
/* POST: */

/* PRE: */
void LinkedList::IReverse() {

	Node^ aNode = nullptr;
	Node^ bNode = head;
	Node^ cNode;

	while(bNode != nullptr) {
		cNode = bNode->Next;
		bNode->Next = aNode;
		aNode = bNode;
		bNode = cNode;
	}

	head = aNode;
}
/* POST: */

/* PRE: */
void LinkedList::RReverse() {
	reverseRecurse(head);
}

void LinkedList::reverseRecurse(Node^ tNode) {
	if(tNode->Next == nullptr) {
		head = tNode;
		return;
	}

	reverseRecurse(tNode->Next);
	tNode->Next->Next = tNode;
	tNode->Next = nullptr;
}
/* POST: */

/* PRE: */
void LinkedList::Clear() {
	Node^ tNode = head;

	while(tNode != nullptr) {
		Node^ tempNode = tNode;
		deleteNode(tNode);
		tNode = tempNode->Next;
	}
}
/* POST: */

/* PRE: */
array<String^>^ LinkedList::toStringArray() {
	array<String^>^ a = gcnew array<String^>(Count());

	Node^ tNode = head;
	int i = 0;
	while(tNode != nullptr){
		a[i] = Convert::ToString(tNode->Value);
		tNode = tNode->Next;
		i++;
	}

	return a;
}
/* POST: */

/* PRE: */
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
/* POST: */


/* PRE: */
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
/* POST: */
