#include "stdafx.h"
#include "RemoveIt.h"

RemoveIt::RemoveIt() {

	String^ t = "c";
	String^ word = "accddeedcd";
	String^ result = removeLetter(word, t);
	String^ breakPoint = "here";
}

String^ RemoveIt::removeLetter(String^ s, String^ target) {

	if(s->Length == 1)
		return s;

	String^ c = s[s->Length - 1].ToString();
	s = s->Remove(s->Length - 1, 1);

	if(c == target) {
		return removeLetter(s, target);	
	}

	return  removeLetter(s, target) + c;
}
