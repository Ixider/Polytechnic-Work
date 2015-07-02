#pragma once

using namespace System;
using namespace System::Collections;

ref class KeyPhraseContainer
{
private:
	ArrayList^ keys;
	ArrayList^ phrases;

public:
	KeyPhraseContainer(void);

	void setKeys(ArrayList^ newKeys) { keys = newKeys; }
	ArrayList^ getKeys() { return keys; }

	void setPhrases(ArrayList^ newPhrases) { phrases = newPhrases; }
	ArrayList^ getPhrases() { return phrases; }
};

