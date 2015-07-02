#pragma once

using namespace System;
using namespace System::Collections::Generic;

// NODE
template <class NT>
ref class PQNODE {
public:
	PQNODE(NT sValue, int sPriorityScore) {
		Value = sValue;
		PriorityScore = sPriorityScore;
	}

	int PriorityScore;
	NT Value;
};

// PRIORITY QUEUE

template <class T>
ref class PriorityQueue {
private:
	List<PQNODE<T>^>^ queue;
	void Sort();
	void QuickSort(int left, int right);
	void SwapItems(int indexOne, int indexTwo);
	int  Partition(int left, int right);

public:
	PriorityQueue(void);

	void Add(T Value, int PriorityScore);
	PQNODE<T>^ Pop();
	PQNODE<T>^ PopEnd();
	PQNODE<T>^ Peek();
	PQNODE<T>^ AtIndex(int i);
	bool IsEmpty();
	bool Contains(T priorityScore);
	int Count();

	String^ topToString();
};

template <class T>
String^ PriorityQueue<T>::topToString() {
	array<int>^ topV = queue[0]->Value;

	String^ str = "";
	for (int i = 0; i < topV->Length; i++) {
		str += topV[i].ToString();
	}

	return str;
}


// IMPLIMENTATION
template <class T>
PriorityQueue<T>::PriorityQueue()
{
	queue = gcnew List<PQNODE<T>^>();
}

/*
	PRE: IsFull() must return false first
*/
template <class T>
void PriorityQueue<T>::Add(T Value, int PriorityScore)
{
	PQNODE<T>^ node = gcnew PQNODE<T>(Value, PriorityScore);
	queue->Add(node);
	Sort();
}
/*
	POST:
*/

/*
	PRE: IsEmpty() must be called first
*/
template <class T>
PQNODE<T>^ PriorityQueue<T>::Pop() {
	PQNODE<T>^ node = queue[0];
	queue->RemoveAt(0);
	return node;
}
/*
	POST:
*/

/*
	PRE: IsEmpty() must be called first
*/
template <class T>
PQNODE<T>^ PriorityQueue<T>::PopEnd() {
	PQNODE<T>^ node = queue[queue->Count - 1];
	queue->RemoveAt(queue->Count - 1);
	return node;
}
/*
	POST:
*/

/*
	PRE: IsEmpty must be called and return false
*/
template <class T>
PQNODE<T>^ PriorityQueue<T>::Peek() {
	return queue[0];
}
/*
	POST: 
*/

/*
	PRE: queue length must be bigger then index given
*/
template <class T>
PQNODE<T>^ PriorityQueue<T>::AtIndex(int i) {
	return queue[i];
}
/*
	POST: 
*/

/*
	PRE: 
*/
template<class T> 
int PriorityQueue<T>::Count() {
	int count = 0;

	for each(PQNODE<T>^ i in queue) 
		count++;

	return count;
}
/*
	POST: 
*/

/*
	PRE: 
*/
template <class T>
bool PriorityQueue<T>::Contains(T Value)
{
	for each(PQNODE<T>^ p in queue)
		if(p->Value == Value)
			return true;

	return false;
}
/*
	POST: 
*/

/*
	PRE:
*/
template <class T>
bool PriorityQueue<T>::IsEmpty()
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

// QUICK SORT
/*
	PRE:
*/
template <class T>
void PriorityQueue<T>::Sort()
{
	QuickSort(0, queue->Count - 1);
}
/*
	POST: 
*/

/*
	PRE: Method starts recursive sort
*/
template <class T>
void PriorityQueue<T>::QuickSort(int left, int right)
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
template <class T>
int PriorityQueue<T>::Partition(int left, int right)
{
	int pivot = queue[left]->PriorityScore;

	//Partition array into secontions above and below the pivot
    while (left < right)
    {
		// Traverses queue from left to right, looking for a index with a PQNODE with a higher pScore than the pivots 
        while (queue[left]->PriorityScore < pivot)
			left++;
  
		// Traverses queue from right to left, looking for a index with a PQNODE with a lower pScore than the pivots
        while (queue[right]->PriorityScore > pivot)
			right--;
 
		// Swaps place of the two items
		if (left < right) {
			SwapItems(left, right);
			left++;
		}
    }

	return right;
}
/*
	POST: 
*/

/*
	PRE:
*/
template <class T>
void PriorityQueue<T>::SwapItems(int firstIndex, int secondIndex) {	
	PQNODE<T>^ temp = queue[secondIndex];
	queue[secondIndex] = queue[firstIndex];
	queue[firstIndex] = temp;
}
/*
	POST:
*/