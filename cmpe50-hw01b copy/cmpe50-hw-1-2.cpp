//============================================================================
// Name        : cmpe50-hw-1-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : deep fry a twinkie
// Date        : February 13, 2022
//============================================================================

#include <iomanip>
#include <iostream>
using namespace std;

double textToValue(string str){
	if(str == "dollar"){
		return 1.00;
	} else if (str == "quarter"){
		return 0.25;
	} else if (str == "dime"){
		return 0.10;
	} else if (str == "nickel"){
		return 0.05;
	} else {
		return 0;
	}
}

int main(){
	//simulate a vending machine the deep fries a twinkie for $3.50
	//only takes dollar, quarter, dime, nickel
	double paid=0;
	string input;
	cout << "It costs $3.50 to buy a deep fried twinkie." << endl;
	cout << " Please enter change.\n(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)" << endl;


	while(paid<3.5){
		cin >> input;
		if (textToValue(input) > 0){
			cout << "You inserted a " << input << ".\n========================================" << endl;
			paid += textToValue(input);
			if(paid<3.5){
				std::cout << std::fixed;
				std::cout << std::setprecision(2);
				cout << "So far, you have entered $" << paid << ". \nYou still owe $" << 3.5-paid << endl;
				cout << "Please enter change.\n(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)" << endl;
			}
		}
	}

	cout << "========================================\nYour change is $" << paid-3.50 << ". Enjoy your deep-fried twinkie." << endl;


	return 0;
	/*
	 * * What is printed in the console:

It costs $3.50 to buy a deep fried twinkie.
 Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
dollar
You inserted a dollar.
========================================
So far, you have entered $1.00.
You still owe $2.50
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
dollar
You inserted a dollar.
========================================
So far, you have entered $2.00.
You still owe $1.50
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
dollar
You inserted a dollar.
========================================
So far, you have entered $3.00.
You still owe $0.50
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
quarter
You inserted a quarter.
========================================
So far, you have entered $3.25.
You still owe $0.25
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
dime
You inserted a dime.
========================================
So far, you have entered $3.35.
You still owe $0.15
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
nickel
You inserted a nickel.
========================================
So far, you have entered $3.40.
You still owe $0.10
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
nickel
You inserted a nickel.
========================================
So far, you have entered $3.45.
You still owe $0.05
Please enter change.
(type 'dollar' or 'quarter' or 'dime' or 'nickel' to simulate paying)
dollar
You inserted a dollar.
========================================
========================================
Your change is $0.95. Enjoy your deep-fried twinkie.

	 */
}
