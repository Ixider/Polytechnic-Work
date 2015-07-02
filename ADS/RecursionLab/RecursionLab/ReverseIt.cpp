#include "stdafx.h"
#include "ReverseIt.h"

ReverseIt::ReverseIt(){

	String^ str = "Sam";
	str = reverseString(str);
}

String^ ReverseIt::reverseString(String^ string) {
	if(string->Length == 1) { 
		return string;
	}
	String^ s = string[0].ToString();
	string = string->Remove(0, 1);

	return  reverseString(string) + s;
}