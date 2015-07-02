#pragma once

using namespace System;

ref class ViginereCipher
{

private:

public:
	ViginereCipher(void);
	String^ decodeString(String^ key, String^ phrase);
	String^ encodeString(String^ key, String^ phrase);
};

