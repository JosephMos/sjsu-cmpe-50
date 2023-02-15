//============================================================================
// Name        : lab01e.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : locating all the prime numbers from 3-k
// Date        : February 01, 2022
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

int main() {

	int k=0;
	bool toReturn = true;

	while (k<3){
		cout << "Please enter an integer larger than 2: ";
		cin >> k;
	}

	cout << "The prime numbers until " << k << " are: ";

	for(int i=3; i<=k; i++){
		for (int j = 2; j < i; j++) {
			        if (i % j == 0) {
			                toReturn = false;
			                break;
			        }
			   }
		if(toReturn){
			cout << i << ", ";
		}
		toReturn = true;
	}

	return 0;
}

/*
 * The output to console:
 *
Please enter an integer larger than 2: 15
The prime numbers until 15 are: 3, 5, 7, 11, 13,
 */

