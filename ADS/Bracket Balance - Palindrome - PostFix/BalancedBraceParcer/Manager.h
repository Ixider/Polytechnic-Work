#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Manager
{
private:
public:
	Manager() {}
	bool BracketBalanced(String^ str);
	bool Palindroms(String^ str);
	String^ PostFixParser(String^ str);
};
