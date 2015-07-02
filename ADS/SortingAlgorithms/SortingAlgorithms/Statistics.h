#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections;

ref class Statistics {

private:
	StreamWriter^ sw;
	String^ generateTimeStamp();


public:
	Statistics();
	void OpenFile(String^ fileName);
	void CloseFile();
	void WriteToFile(String^ str);
};