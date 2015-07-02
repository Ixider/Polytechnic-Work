#include "StdAfx.h"
#include "ViginereCipher.h"


ViginereCipher::ViginereCipher(void)
{
}


/*
	Given a key and phrase will encrpy string with vigineres cipher

	PRE: string inputs must be converted to uppercase
*/
String^ ViginereCipher::encodeString(String^ key, String^ phrase) {

	// Used to convert character from ascii value to 0 - 25 alphabet index 65 is 'A'
	int asciiDifference = 65;
	String^ finalWord = "";

	int i = 0;
	for each(wchar_t c in phrase) {
		if(c != ' ') { // Ignore spaces
			int shiftValue = Convert::ToInt32(key[i]) - asciiDifference;
			int charValue = Convert::ToInt32(c) - asciiDifference;
			int result = ((charValue + shiftValue) % 26) + asciiDifference;
			finalWord += Convert::ToChar(result);
		} else { // add the spaces to string
			finalWord += Convert::ToChar(' ');
		}
		i++;
		i = i % key->Length;
	}

	return finalWord;
}

/*
	PRE: Inputs must be coverted to upper case
*/
String^ ViginereCipher::decodeString(String^ key, String^ phrase)
{
	array<Char>^ kChars = key->ToCharArray();	
	array<Char>^ pChars = phrase->ToCharArray();

	String^ finalWord = "";

	int zero = 65;

	int count = 0;
    for(int i = 0; i < pChars->Length; i++)
	{
		if(pChars[i] != ' ')
		{
			int shiftValue = Convert::ToInt32(kChars[count]) - zero;
			int charValue = Convert::ToInt32(pChars[i]) - zero;

			int result = (charValue - shiftValue);

			if(result < 0)
				result = 26 - (result * -1);

			result += zero; 

			finalWord += Convert::ToChar(result);

			count++;
			count = count % kChars->Length;
		}
		else
		{
			finalWord += Convert::ToChar(' ');
		}
	}
	
	return finalWord;
}