//============================================================================
// Name        : lab02a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : create 3 add functions
// Date        : February 08, 2022
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

int add(int num1, int num2){
	return num1 + num2;
}

double add(double num1, double num2){
	return num1 + num2;
}

string add(string str1, string str2){
	string str = str1 + " " + str2;
	return str;
}

int main() {

	int option = 0;

	while (option != 1 && option != 2 && option != 3){
		cout << "Would you like to add 2 integers, doubles, or strings?" << endl;
		cout << "(Enter 1 for integers, 2 for doubles, 3 for strings)" << endl;
		cin >> option;
	}

	switch (option){
	case 1:
		int oneI, twoI;
		cout << "Enter 2 integers that you would like to add:" << endl;
		cin >> oneI;
		cin >> twoI;
		cout << "" << add(oneI, twoI) << endl;
		break;
	case 2:
		double oneD, twoD;
		cout << "Enter 2 doubles that you would like to add:" << endl;
		cin >> oneD;
		cin >> twoD;
		cout << "" << add(oneD, twoD) << endl;
		break;
	case 3:
		string oneS, twoS;
		cout << "Enter 2 strings that you would like to add:" << endl; // why isnt this working
		cin >> oneS >> twoS;
		//cin >> oneS;
		//cout << "";
		//cin >> twoS;
		//getline (cin, oneS);
		//cout << endl;
		//getline (cin, twoS);
		cout << "" << add(oneS, twoS) << endl;
		break;
	}



	return 0;
}

/*
 * The output to console:
 *
Would you like to add 2 integers, doubles, or strings?
(Enter 1 for integers, 2 for doubles, 3 for strings)
4
Would you like to add 2 integers, doubles, or strings?
(Enter 1 for integers, 2 for doubles, 3 for strings)
3
Enter 2 strings that you would like to add:
asdf
qwer
asdf qwer
 */

