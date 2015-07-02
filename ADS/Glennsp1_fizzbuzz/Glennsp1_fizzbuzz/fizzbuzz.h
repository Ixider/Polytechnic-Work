#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class fizzbuzz {
private:
	static const int UPPER_LIMIT = 100;
	static const int LOWER_LIMIT = 1;

	ListBox^ display;
	void compute(int n);
	String^ evaluateN(int n);
	void displayResult(String^ str);

public:
	fizzbuzz(ListBox^ lb);
    void RunFizzBuzz();
};