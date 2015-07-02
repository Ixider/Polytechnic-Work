#pragma once

using namespace System;

ref class Patient
{
	private:
		String^ name;
		int priorityScore;

	public:
		Patient(String^ sName, int sPriorityScore);
		
		String^ getName() { return name; }
		int getPriorityScore() { return priorityScore; }
};

