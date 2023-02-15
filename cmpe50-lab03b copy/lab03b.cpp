//============================================================================
// Name        : lab03b.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : _______
// Date        : February 15, 2022
//============================================================================

#include <iostream>
using namespace std;

int main(){
	int arr[3][3];
	bool upper = false, lower=false;

	cout << "Give me 9 integers. Lets go:" << endl;
	int justForFun=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			justForFun++;
			cout << "Integer number " << justForFun << ": ";
			cin >> arr[i][j];
		}
	}

	if(arr[0][0] == 0 && arr[0][1] == 0 && arr[1][0] == 0){
		upper=true;
	} else if(arr[0][1] == 0 && arr[0][2] == 0 && arr[1][2] == 0){
		upper = true;
	}

	if(arr[1][0] == 0 && arr[2][0] == 0 && arr[2][1] == 0){
		lower = true;
	} else if(arr[1][2] == 0 && arr[2][1] == 0 && arr[2][2] == 0){
		lower = true;
	}

	for(int i = 0; i<3; i++){
		for (int j=0; j<3; j++){
			cout << " " << arr[i][j];
			if (j == 2){
				cout << "\n";
			}
		}
	}//upper boolean is lower becasure this is confusing

	if(upper && lower){
		cout << "This is both an upper and lower matrix." << endl;
	} else if(upper){
		cout << "This is an lower triangular matrix." << endl;
	} else if(lower){
		cout << "This is a upper triangular matrix." << endl;
	} else {
		cout << "This is a normal matrix." << endl;
	}

	return 0;
}
/*
 * Output to console:
 *
Give me 9 integers. Lets go:
Integer number 1: 1
Integer number 2: 2
Integer number 3: 3
Integer number 4: 4
Integer number 5: 5
Integer number 6: 0
Integer number 7: 7
Integer number 8: 0
Integer number 9: 0
 1 2 3
 4 5 0
 7 0 0
This is a lower triangular matrix.
 */
