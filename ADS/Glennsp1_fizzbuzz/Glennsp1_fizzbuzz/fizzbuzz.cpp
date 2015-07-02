#include "stdafx.h"
#include "fizzbuzz.h"

fizzbuzz::fizzbuzz(ListBox^ lb) {
	display = lb;
}

void fizzbuzz::RunFizzBuzz() {
	compute(LOWER_LIMIT);
}

void fizzbuzz::compute(int n) {
	if(n > UPPER_LIMIT) 
		return; 

	String^ str = evaluateN(n);
	displayResult(str);

	compute(n + 1);
}	

//Puts n through test cases to determin output
String^ fizzbuzz::evaluateN(int n) {
	String^ str = "";

	if((n % 3) == 0) 
		str += "fizz";

	if((n % 5) == 0)
		str += "buzz";

	if(str->Length == 0)
		str = Convert::ToString(n);

	return str;
}

// Adds the evaluated string result to the display listbox on the UI
void fizzbuzz::displayResult(String^ str) {
	display->Items->Add(str);
}