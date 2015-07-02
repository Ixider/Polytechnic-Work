#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class cqNode
{
private:
public:
	cqNode() {}
	char cValue;
	cqNode^ Next;
};

ref class chQueue
{
private:
	cqNode^ head;
	cqNode^ tail;
	void addNode(cqNode^ newNode);
	void deleteNode(cqNode^ stackTop);


public:
	chQueue(void);

	void Push(char n);
	char Peek();
	char Pop();
	void PushRange(array<char>^ range);
	int Count();	
	bool IsEmpty();
	char IndexOf(int n);
};

