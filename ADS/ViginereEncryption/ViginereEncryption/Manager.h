#pragma once
#include "FileReader.h"
#include "ViginereCipher.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

ref class Manager
{
private:
	ListBox^ listBox;
	FileReader^ fileReader;
	ViginereCipher^ cipher;

public:
	Manager(ListBox^ x);
	
	ArrayList^ runDecryption(String^ fileName);
	ArrayList^ iterateKeys(ArrayList^ keys, ArrayList^ phrases);

	String^ encryptInput(String^ key, String^ phrase);
	String^ decryptInput(String^ key, String^ phrase);
};

