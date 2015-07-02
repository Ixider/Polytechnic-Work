#include "StdAfx.h"
#include "FileReader.h"


FileReader::FileReader(void)
{
	
}

KeyPhraseContainer^ FileReader::readFile(String^ fileName)
{
	ArrayList^ fileStrings = gcnew ArrayList();

	StreamReader^ reader = gcnew StreamReader(fileName);
	try
	{
		String^ str;

		while((str = reader->ReadLine()) != nullptr)
		{
			fileStrings->Add(str);
		}
	}
	catch(Exception^ e)
	{

	}
	finally
	{
		delete reader;
	}
	
	KeyPhraseContainer^ kp = processFile(fileStrings);

	return kp;
}

/*
	PRE:
*/
KeyPhraseContainer^ FileReader::processFile(ArrayList^ fileStrings)
{
	int index = Convert::ToInt32(fileStrings[0]);

	KeyPhraseContainer^ kp = gcnew KeyPhraseContainer();

	ArrayList^ keys = gcnew ArrayList();
	ArrayList^ phrases = gcnew ArrayList();

	for(int i = 1; i < fileStrings->Count; i++)
	{
		if(i <= index)
		{
			keys->Add(fileStrings[i]);
		}
		else
		{
			phrases->Add(fileStrings[i]);
		}
	}

	kp->setKeys(keys);
	kp->setPhrases(phrases);

	return kp;
}
/*
	POST:
*/
