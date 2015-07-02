#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class Node {
private:
public:
	Node(int id, String^ name, String^ species, String^ cageNumber, String^ age, String^ food) {
		Id = id;
		Name = name;
		Species = species;
		CageNumber = cageNumber;
		Age = age;
		Food = food;
	}

	int Id;
	String^ Name;
	String^ Species;
	String^ CageNumber;
	String^ Age;
	String^ Food;

};

ref class ADTable {

private:
	array<Node^>^ nodes;

public:
	ADTable();

	void Insert(Node^ newRecord);
	void Delete(int key);
	void SortTable();
	String^ PrintTable();
	Node^ RetrieveElement(int key);
};