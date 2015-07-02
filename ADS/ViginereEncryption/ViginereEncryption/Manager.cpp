#include "StdAfx.h"
#include "Manager.h"


Manager::Manager(ListBox^ listBox)
{
	listBox = listBox;
	fileReader = gcnew FileReader();
	cipher = gcnew ViginereCipher();
}

ArrayList^ Manager::runDecryption(String^ fileName)
{
	KeyPhraseContainer^ kpc = fileReader->readFile(fileName);

	ArrayList^ keys = kpc->getKeys();
	ArrayList^ phrases = kpc->getPhrases();

	ArrayList^ index = iterateKeys(keys, phrases);
	return index;
}

/*
	PRE:
*/
ArrayList^ Manager::iterateKeys(ArrayList^ keys, ArrayList^ phrases)
{
	ArrayList^ results = gcnew ArrayList();

	int keyIndex = 0;

	for(int i = 0; i < keys->Count; i++)
	{
		String^ key = Convert::ToString(keys[i]);

		for(int x = 0; x < phrases->Count; x++)
		{
			String^ phrase = Convert::ToString(phrases[x]);

			String^ str = cipher->decodeString(key, phrase);
			//System::Windows::Forms::DialogResult result = MessageBox::Show(str, "Does this make sense?", MessageBoxButtons::YesNo);

			results->Add(str);
		}
	}

	return results;
}
/*
	POST: 
*/

String^ Manager::encryptInput(String^ key, String^ phrase) {
	String^ result = cipher->encodeString(key, phrase);
	return result;
}

String^ Manager::decryptInput(String^ key, String^ phrase) {
	String^ result = cipher->decodeString(key, phrase);
	return result;
}
