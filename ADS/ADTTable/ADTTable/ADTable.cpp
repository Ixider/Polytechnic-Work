#include "stdafx.h"
#include "ADTable.h"

ADTable::ADTable() {
	nodes = gcnew array<Node^>(100);
}

/*
	PRE:
*/
void ADTable::Insert(Node^ newRecord) {

}
/*
	POST:
*/

/*
	PRE:
*/
void ADTable::Delete(int key) {

}
/*
	POST:
*/

/*
	PRE:
*/
void ADTable::SortTable() {

}
/*
	POST:
*/

/*
	PRE:
*/
String^ ADTable::PrintTable() {
	return "";
}
/*
	POST:
*/

/*
	PRE:
*/
Node^ ADTable::RetrieveElement(int key) {
	return nodes[key];
}
/*
	POST:
*/