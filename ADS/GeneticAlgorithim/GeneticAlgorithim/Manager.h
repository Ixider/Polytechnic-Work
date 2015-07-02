#pragma once
#include "GAEngine.h"

using namespace System;

ref class Manager {
private:
	GAEngine^ ga;
public:
	void Run();
	Manager(ListBox^ lb);
};