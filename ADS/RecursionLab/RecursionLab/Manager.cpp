#include "stdafx.h"
#include "Manager.h"

Manager::Manager() {
	SumToN^ s = gcnew SumToN();
	ReverseIt^ r = gcnew ReverseIt();
	Palindrome^ p = gcnew Palindrome();
	RemoveIt^ rm = gcnew RemoveIt();
}