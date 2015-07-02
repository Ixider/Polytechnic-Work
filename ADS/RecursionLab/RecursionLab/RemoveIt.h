#pragma once

using namespace::System;

ref class RemoveIt{
private:
public:
	RemoveIt();
	String^ removeLetter(String^ s, String^ target);
};