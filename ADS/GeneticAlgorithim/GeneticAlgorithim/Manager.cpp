#include "stdafx.h"
#include "Manager.h"

Manager::Manager(ListBox^ lb) {
	ga = gcnew GAEngine(lb);
}

void Manager::Run() {
	ga->Run();
}