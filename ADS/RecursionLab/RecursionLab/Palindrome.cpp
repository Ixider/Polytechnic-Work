#include "stdafx.h"
#include "Palindrome.h"

Palindrome::Palindrome() {
	String^ s1 = "hannah";
	bool result1 = isPalindrome(s1);

	String^ s2 = "notpalindrome";
	bool result2 = isPalindrome(s2);

	String^ s3 = "hah";
	bool result3 = isPalindrome(s3);

	String^ s4 = "haaxzah";
	bool result4 = isPalindrome(s4);

	String^ breakPoint = "here";
}

bool Palindrome::isPalindrome(String^ str){

	if(str->Length <= 1 ) {
		return true;
	}		
	else if (str[0] == str[str->Length -1]){
		str = str->Remove(0, 1);
		str = str->Remove(str->Length -1, 1);
		return isPalindrome(str);
	}
}
