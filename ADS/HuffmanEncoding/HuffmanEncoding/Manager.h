#pragma once
#include "TreeDrawer.h"
#include "HuffmanFactory.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class Manager {

private:
	HuffmanFactory^ hFactory;
	TreeDrawer^ treeDisplay;

	BinarySearchTree^ huffmanTree;
	Graphics^ gfx;

	ListBox^ codeDisplay;
	Label^ decodeDisplay;
	Label^ originalSize;
	Label^ encodedSize;
	void display();

	String^ originalString;
	void setOrigonalSize();
	void setEncodedSize();
	void buildString(int count, String^ symbol);

public:
	Manager(ListBox^ listBox, Label^ displayLabel, Label^ oSizeLabel, Label^ eSizeLabel, Graphics^ graphics);
	void decodeString(String^ string);
	void takeInput(String^ string);
	void takeInput(array<String^>^ strings);


};