#include "stdafx.h"
#include "SumToN.h"

SumToN::SumToN(){

	int sum = 0;
	sum = SumOfN(5);
	String^ breakPoint = "here";
}

int SumToN::SumOfN(int n) {
	
	if(n == 1) {
		return n;
	}
	return SumOfN(n - 1) + n;
}