#pragma once
#include "KeyPhraseContainer.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::IO;

ref class FileReader
{
	private:

	public:
		FileReader(void);
		KeyPhraseContainer^ readFile(String^ fileName);
		KeyPhraseContainer^ processFile(ArrayList^ fileStrings);
};

