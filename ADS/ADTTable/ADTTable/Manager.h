#pragma once
#include "ADTable.h"

using namespace System;
using namespace System::IO;

ref class Manager {

private:
	ADTable^ adtTable;
	void constructTableFromFlatFile();

public:
	Manager();


};
