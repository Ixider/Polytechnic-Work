#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;


ref class Test
{
private:
public:
	Test();
	String^ RunTests();

	String^ PushTest();

	String^ PopTest();
	String^ PopOnEmpty();

	String^ PeekTest();
	String^ resultsToString(String^ name, array<String^>^ actions, int expected, int result, bool pass);
};