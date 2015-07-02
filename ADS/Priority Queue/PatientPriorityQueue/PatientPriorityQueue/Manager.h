#pragma once

using namespace System;

#include "PriorityQueue.h"

ref class Manager
{
	private:
		Random^ rGen;
		PriorityQueue^ priorityQueue;

	public:
		Manager(void);
		void createPatient(String^ name);
		int generatePriorityScore();
		array<String^>^ toString();
};

