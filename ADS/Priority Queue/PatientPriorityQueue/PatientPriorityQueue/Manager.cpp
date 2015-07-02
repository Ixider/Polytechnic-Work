#include "StdAfx.h"
#include "Manager.h"


Manager::Manager(void)
{
	rGen = gcnew Random();
	priorityQueue = gcnew PriorityQueue();
}

/*
	PRE: User has inputed a name
*/
void Manager::createPatient(String^ name)
{
	if(!priorityQueue->IsFull())
	{
		int priorityScore = generatePriorityScore();
		Patient^ patient = gcnew Patient(name, priorityScore);

		priorityQueue->insert(patient);
	}
}
/*
	POST: if the queue is not full, a new patient will have been inserted into the priority queue
*/


/*
	PRE: priority queue must not be full
*/
int Manager::generatePriorityScore()
{
	int r = rGen->Next(100);
	return r;
}
/*
	POST: A number between 0 and 100 has been returned to be used as a priority score for patients
*/


array<String^>^ Manager::toString()
{
	return priorityQueue->toString();
}
