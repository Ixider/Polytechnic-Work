#pragma once

using namespace System;
using namespace System::Collections;

ref class ArrayFactory {
private:
	Random^ rGen;
	void PopulateArray(array<int>^ emptySet);

public:
	ArrayFactory();
	array<int>^ MakeArray(int setSize);
};