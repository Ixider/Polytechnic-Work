#include "StdAfx.h"
#include "Statistics.h"

Statistics::Statistics() {
	
}

void Statistics::OpenFile(String^ fileName){ 
	String^ endFileName = fileName +" - "+generateTimeStamp() + " - Test Results";
	sw = gcnew StreamWriter(endFileName);
}

/*
	PRE: OpenFile must have been called at some point
*/
void Statistics::CloseFile() {
	sw->Close();
}


void Statistics::WriteToFile(String^ str) {
	sw->WriteLine(str);
}

String^ Statistics::generateTimeStamp(){
	DateTime date = DateTime::Now;
	String^ timeStamp = date.ToString("dddd, dd MMMM yyyy");
	return timeStamp;
}

