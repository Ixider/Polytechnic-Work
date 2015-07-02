#pragma once
#include "Node.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class LinkedList
{
private:
	Node^ head;
	Node^ tail;
	void addNode(Node^ newNode);
	void deleteNode(Node^ stackTop);


public:
	LinkedList(void);

	void Push(int n);
	int Peek();
	int Pop();
	int Count();	
	bool IsEmpty();
	int IndexOf(int n);
};
