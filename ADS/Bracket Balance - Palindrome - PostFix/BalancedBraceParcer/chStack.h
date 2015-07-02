#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class cNode
{
private:
public:
	cNode() {}
	char cValue;
	cNode^ Next;
};

ref class chStack
{
private:
	cNode^ head;
	cNode^ tail;
	void addNode(cNode^ newNode);
	void deleteNode(cNode^ stackTop);


public:
	chStack(void);

	void Push(char n);
	char Peek();
	char Pop();
	void PushRange(array<char>^ range);
	int Count();	
	bool IsEmpty();
	char IndexOf(int n);
};

