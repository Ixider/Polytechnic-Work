#include "stdafx.h"
#include "Manager.h"

Manager::Manager() {
	constructTableFromFlatFile();
	adtTable = gcnew ADTable();

}

enum FType { ID, NAME, SPECIES, CAGENUMBER, AGE, FOOD };
void Manager::constructTableFromFlatFile() {
	StreamReader^ reader = gcnew StreamReader("Zoo.txt");

	while(reader->Peek() >= 0) {
		array<String^, 1>^ line = reader->ReadLine()->Split(',');
		
		Node^ node = gcnew Node(
				Convert::ToInt16(line[FType::ID]),
				line[FType::NAME],
				line[FType::SPECIES],
				line[FType::CAGENUMBER],
				line[FType::AGE],
				line[FType::FOOD]
			);

			adtTable->Insert(node);
	}
}