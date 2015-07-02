#include "stdafx.h"
#include "Test.h"
#include "iStack.h"

Test::Test() {
}

String^ Test::RunTests() {
	String^ TestResults = "";
	
	TestResults += PushTest();
	TestResults += PopTest();
	//TestResults += PopOnEmpty();
	
	return TestResults;
}

String^ Test::PushTest() {

	iStack^ stack = gcnew iStack();

	stack->Push(2);
	stack->Push(1);

	int expected = 2;
	int result = stack->Count();

	String^ name = "Basic Push";
	array<String^>^ actions = { "Push(2)", "Push(1)", "Count()" };
	bool pass = (result == expected);
	
	return resultsToString(name, actions, expected, result, pass);
}

String^ Test::PopTest() {

	iStack^ stack = gcnew iStack();

	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	int result = stack->Pop();
	int expected = 3;

	String^ name = "Basic Pop";
	array<String^>^ actions = { "Push(1)", "Push(2)", "Push(3)", "Pop()" };
	bool pass = (result == expected);

	return resultsToString(name, actions, expected, result, pass);
}

String^ Test::PopOnEmpty() {

	iStack^ stack = gcnew iStack();

	int result = stack->Pop();
	int expected = 1;

	String^ name = "Basic Pop";
	array<String^>^ actions = { "Pop()" };
	bool pass = (result == expected);

	return resultsToString(name, actions, expected, result, pass);
}

String^ Test::PeekTest() {
	return "";
}

String^ Test::resultsToString(String^ name, array<String^>^ actions, int expected, int result, bool pass) {
	String^ str = "------------------------------------------,";

	str += name + ",,";

	str += "Actions:,";
	for each(String^ s in actions)
		str += s + ",";

	str += ",Expected: " + Convert::ToString(expected) + ",";
	str += "Result: " + Convert::ToString(result) + ",";
	str += ",PASSED: " + Convert::ToString(pass) + ",";
	str += "------------------------------------------,";
	return str;
}