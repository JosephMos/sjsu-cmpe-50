//============================================================================
// Name        : cmpe50-hw-1-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : write a maximum function
// Date        : February 13, 2022
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

double maximum(double num1, double num2){
	if(num1>num2){
		return num1;
	} else {
		return num2;
	}
}

double maximum(double num1, double num2, double num3){
	if(num1>num2 && num1>num3){
		return num1;
	} else if(num2>num1 && num2>num3){
		return num2;
	} else {
		return num3;
	}
}

int main(){
	double one=3.3, two=9.48, three=1.222;

	cout << "The max value between " << one << " and " << two << " is " << maximum(one, two) << endl;
	cout << "The max value between " << one << ", " << two << ", and " << three << " is " << maximum(one, two, three) << endl;

	return 0;
	/*
	 * Output to console:

The max value between 3.3 and 9.48 is 9.48
The max value between 3.3, 9.48, and 1.222 is 9.48
	 */
}
