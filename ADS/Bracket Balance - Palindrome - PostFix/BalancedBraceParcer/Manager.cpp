#include "StdAfx.h"
#include "Manager.h"
#include "chStack.h"
#include "chQueue.h"
#include "iStack.h"
/*
	Takes a string and evaluates wether or not { or } 
	characters present within the string are balanced.
*/
bool Manager::BracketBalanced(String^ str) {

	chStack^ stack = gcnew chStack();

	bool isBalanced = false;
	for(int i = 0; i < str->Length; i++) {
		if(str[i] == '{') // push on open brackets
			stack->Push(str[i]);
		if(str[i] == '}') // pop off the previouse open bracket.
			stack->Pop();
	}

	if(stack->IsEmpty()) // if stack is left empty then the brackets are balanced 
		isBalanced = true;

	return isBalanced;	
}

/*
	Evaluates string to see if the character sequence are the same forwards
	and backwards. Will return false with ' ' inputs and is case sensitive.
*/
bool Manager::Palindroms(String^ str) {
	chQueue^ queue = gcnew chQueue();
	chStack^ stack = gcnew chStack();

	// Add each character to a stack and a queue
	for each(char c in str) {
		stack->Push(c);
		queue->Push(c);
	}

	// Increment a counter for matched characters
	int count = 0;
	for(int i = 0; i < str->Length; i++) 
		if(stack->Pop() ==  queue->Pop())
			count++;	
	
	return (count == str->Length);
}


/*
	Takes a string input in Post Fix notation and calculates the result.
	numbers are delimited with , and only checks for +, -, *, / math operators
*/
String^ Manager::PostFixParser(String^ str) {
	iStack^ stack = gcnew iStack();
	String^ strBuilder = "";
	for each(wchar_t c in str) {
		// if the character is not a math operator or a ',' delimiter add char to string.
		if(c != ',' && c != '+' && c != '*' && c != '/' && c != '-') {
			strBuilder += Convert::ToString(c); 
		} else if(c == ',') { // commas are used as a delimiter for the end of a number.
			stack->Push(Convert::ToInt32(strBuilder)); // add number to stack
			strBuilder = ""; // Reset String
		} else if(c == '+') { // gets last two numbers added to the stack, preforms operation and puts it back. 
			stack->Push(stack->Pop() + stack->Pop());
		} else if(c == '*') {
			stack->Push(stack->Pop() * stack->Pop());
		} else if(c == '/') {
			stack->Push(stack->Pop() / stack->Pop());
		} else if(c == '-') {
			stack->Push(stack->Pop() - stack->Pop());
		}
	}

	int result = stack->Pop(); // Last number in the stack will be the answer
	return Convert::ToString(result);
}


//	 ALTERNATIVE IMPLIMENTATION AS CODED TO MY PSUDO BEFORE LOOKING AT SOLUTION
//bool Manager::CheckBalanced(String^ str) {
//	for(int i = 0; i < str->Length; i++) {
//		char prev = ' ';
//		if(!stack->IsEmpty())
//			prev = stack->Peek();
//
//		// pushes next brace onto stack
//		if(str[i] == '{' || str[i] == '}') {
//			stack->Push(str[i]);			
//		}
//
//		if(prev != ' ') { //
//			if(str[i] == '}' && prev == '{') { 
//				stack->Pop();
//				stack->Pop();
//			}
//		}
//	}
//	if(stack->IsEmpty()) // at end of string if there is remaining items in the stack the string is unbalanced
//		return true;
//
//	return false;
//}