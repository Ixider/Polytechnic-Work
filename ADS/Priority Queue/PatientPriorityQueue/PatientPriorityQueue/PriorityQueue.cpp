#include "StdAfx.h"
#include "PriorityQueue.h"


PriorityQueue::PriorityQueue(void)
{
	queue = gcnew array<Patient^>(10);
}

/*
	PRE: IsFull() must return false first
*/
void PriorityQueue::insert(Patient^ p)
{
	queue[queue->Length - 1] = p;
	QuickSort();
}
/*
	POST:
*/

/*
	PRE: IsEmpty() must be called first
*/
Patient^ PriorityQueue::pop()
{
	Patient^ p = queue[0];
	shiftDown();

	return p;
}
/*
	POST:
*/

/*
	PRE: IsEmpty must be called and return false
*/
Patient^ PriorityQueue::peek()
{
	return queue[0];
}
/*
	POST: 
*/

/*
	PRE: 
*/
bool PriorityQueue::Contains(int priorityScore)
{
	for each(Patient^ p in queue)
		if(p->getPriorityScore() == priorityScore)
			return true;

	return false;
}
/*
	POST: 
*/

/*
	PRE: Must be called from POP()
*/
void PriorityQueue::shiftDown()
{
	for(int i = 1; i < getIndexOfLastElement() + 1; i++)
	{
		queue[(i - 1)] = queue[i];
	}
}
/*
	POST: 
*/

/*
	PRE:
*/
void PriorityQueue::QuickSort()
{
	QuickSort(0, getIndexOfLastElement());
}
/*
	POST: 
*/

/*
	PRE: Method starts recursive sort
*/
void PriorityQueue::QuickSort(int left, int right)
{
	if(left < right)
	{
		int pivot = Partition(left, right);
 
		if(pivot > 1)
			QuickSort(left, pivot - 1);
 
		if(pivot + 1 < right)
			QuickSort(pivot + 1, right);
	}
}

/*
	PRE:
*/
int PriorityQueue::Partition(int left, int right)
{
	int pivot = queue[left]->getPriorityScore();

	//Partition array into secontions above and below the pivot
    while (true)
    {
		// Traverses queue from left to right, looking for a index with a patient with a higher pScore than the pivots 
        while (queue[left]->getPriorityScore() > pivot)
			left++;
  
		// Traverses queue from right to left, looking for a index with a patient with a lower pScore than the pivots
        while (queue[right]->getPriorityScore() < pivot)
			right--;
 
		// Swaps place of the two items
		if (left < right)
		{
			SwapItems(left, right);
		}
		else
		{
			// returns value to be used in the next iteration as pivot
			return right;
		}
    }
}
/*
	POST: 
*/

/*
	PRE:
*/
void PriorityQueue::SwapItems(int firstIndex, int secondIndex)
{
	
	Patient^ temp = queue[secondIndex];
	queue[secondIndex] = queue[firstIndex];
	queue[firstIndex] = temp;
}
/*
	POST:
*/

 
/*
	PRE:
*/
bool PriorityQueue::IsFull()
{
	for(int i = 0; i < queue->Length; i++)
	{
		if(queue[i] == nullptr)
			return false;
	}

	return true;
}
/*
	POST: Queue must have at least one empty space.
*/


/*
	PRE:
*/
bool PriorityQueue::IsEmpty()
{
	for(int i = 0; i < queue->Length; i++)
	{
		if(queue[i] != nullptr)
			return false;
	}

	return true;
}
/*
	POST: Queue must contain elements
*/

/*
	PRE: IsFull Must return false
*/
int PriorityQueue::getIndexOfLastElement()
{
	int count = 0;
	for(int i = 0; i < queue->Length; i++)
	{
		if(queue[i] != nullptr)
			count++;
	}

	return (count - 1);
}
/*
	POST: 
*/

array<String^>^  PriorityQueue::toString() 
{
	array<String^>^ strings = gcnew array<String^>(getIndexOfLastElement() + 1);

	for(int i = 0; i < strings->Length; i++)
	{
		String^ pS = Convert::ToString(queue[i]->getPriorityScore());
		String^ name = queue[i]->getName();

		strings[i] = pS + " " + name;
	}

	return strings;
}
