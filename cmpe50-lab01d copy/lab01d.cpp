//============================================================================
// Name        : lab01d.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : factorial of f
// Date        : February 01, 2022
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int f, toReturn=1;
	cout << "enter an integer" << endl;
	cin >> f;

	if(f == 0){
		toReturn = 0;
	} else if(f<0){//neg
		for(int i=f; i<0; i++){
			toReturn *=f;
		}
	} else {//if f>0
		for (int i=f; i>0; i--){
			toReturn *=f;
		}
	}

	cout << "the factorial of " << f << " is " << toReturn << endl;

	return 0;
}

/*
 * The output to console:
 *
enter an integer
5
the factorial of 5 is 3125
 */
