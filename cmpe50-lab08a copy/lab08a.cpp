//============================================================================
// Name        : lab08a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : plane
// Date        : April 12, 2022
//============================================================================

#include <string>
#include <iostream>
using namespace std;

void assignSeats(istream instream) {

	cout << "There is a skinny plane. How many rows does it have?";
	int length;
	instream >> length;
	while (length < 1) {
		cout << "This plane must have atleast 1 row." << endl;
		cout << "Enter the number of rows: ";
		instream >> length;
	}

	if (length >= 15) {
		cout << "Its a skinny, but long plane with " << length << " rows."
				<< endl;
	} else if (length < 7) {
		cout << "Its a very small plane with only " << length << " rows."
				<< endl;
	} else {
		cout << "Its a plane with " << length << " rows." << endl;
	}

	int *arr = new int[4][length];

	while (true) { //break when no more saets, or user says done
		cout << "Which seat would you like?" << endl;
		cout << "(Enter in the format '3A' or '4C')" << endl;
		cout << "(or enter 'done' if you are done)" << endl;
		string input = "";
		instream >> input;
		int row = 0, col = 0;
		if (input.back() == 'A') {
			col = 0;
		} else if (input.back() == 'B') {
			col = 1;
		} else if (input.back() == 'C') {
			col = 2;
		} else if (input.back() == 'D') {
			col = 3;
		}
	}

}

void e1() {

}

int main() {

	e1();

	return 0;
}
/*
 * Output to console:
 *

 */
