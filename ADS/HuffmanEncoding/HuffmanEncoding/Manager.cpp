#include "stdafx.h"
#include "Manager.h"

Manager::Manager(ListBox^ listBox, Label^ displayLabel, Label^ oSizeLabel, Label^ eSizeLabel, Graphics^ graphics) {
	codeDisplay = listBox;
	gfx = graphics;
	hFactory = gcnew HuffmanFactory();
	decodeDisplay = displayLabel;

	originalSize = oSizeLabel;
	encodedSize = eSizeLabel;

}
/*
	PRE: Tree must not be null
*/
void Manager::display() {
	if(!huffmanTree->isEmpty()) {
		huffmanTree->drawTree(gfx);
		huffmanTree->generateCodes();
		codeDisplay->Items->Clear();

		for each(KeyValuePair<String^, String^>^ item in huffmanTree->CodeStore) {
			codeDisplay->Items->Add(item->Value + " " + Convert::ToString(item->Key));
		}

		setEncodedSize();
	}
}
/*
	POST: 
*/


void Manager::decodeString(String^ string) {

	decodeDisplay->Text = huffmanTree->decodeString(string);
}

void Manager::takeInput(String^ string) {
	originalString = string;
	setOrigonalSize();
	huffmanTree = hFactory->ConstructHuffmanTree(string);
	display();
}
 // Things started to get a bit messy in here at 1am hence everything below.
#define bSize 8
void Manager::takeInput(array<String^>^ strings) {
	originalString = "";

	List<String^>^ symbols = gcnew List<String^>();
	List<int>^ frequencies = gcnew List<int>();

	int bitCount = 0;
	for(int i = 0; i < strings->Length/2; i++) {
		if(strings[i] != "") {
			symbols->Add(strings[i]);
			bitCount += (bSize * Convert::ToInt16(strings[(strings->Length/2) + i]));
			frequencies->Add(Convert::ToInt16(strings[(strings->Length/2) + i]));	

			buildString(Convert::ToInt16(strings[(strings->Length/2) + i]), strings[i]);
		}
	}

	setOrigonalSize();

	huffmanTree = hFactory->ConstructHuffmanTree(symbols, frequencies);
	display();
}


void Manager::setOrigonalSize() {
	originalSize->Text = Convert::ToString((originalString->Length * bSize));
}

void Manager::setEncodedSize() {
	String^ encodedString = "";
	for(int i = 0; i < originalString->Length; i++) {
		encodedString += huffmanTree->CodeStore[Convert::ToString(originalString[i])];
	}

	encodedSize->Text = Convert::ToString(encodedString->Length);
}

void Manager::buildString(int count, String^ symbol) {
	for( int i = 0; i < count; i++) {
		originalString += symbol;
	}
}