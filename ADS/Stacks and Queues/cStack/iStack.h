#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Node
{
private:
public:
	Node() {}
	int Value;
	Node^ Next;
};

ref class iStack
{
private:
	Node^ head;
	Node^ tail;
	void addNode(Node^ newNode);
	void deleteNode(Node^ stackTop);


public:
	iStack(void);

	void Push(int n);
	int Peek();
	int Pop();
	void PushRange(array<int>^ range);
	int Count();	
	bool IsEmpty();
	int IndexOf(int n);
};




