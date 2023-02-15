//============================================================================
// Name        : cmpe50-hw-4-3.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : piglatin using string class
// Date        : March 08, 2022
//============================================================================

#include <string>
#include <iostream>
using namespace std;

string piglatin(string input){
	string output;
	for(int i=0; i<input.length(); i++){
		input.at(i) = tolower(input.at(i));
	}
	if (input.at(0) == 'a' || input.at(0) == 'e' || input.at(0) == 'i' || input.at(0) == 'o' || input.at(0) == 'u'){
		output = input + "way";
	} else {
		output = input.substr(1, input.length()-1) + input.at(0) + "ay";
	}
	output.at(0) = toupper(output.at(0));

	return output;
}

void e3(){//works
	cout << "Enter your first and last name and I shall convert your name to pig-latin!" << endl;
	string first, last;
	cin >> first >> last;
	cout << "Your name in pig-latin is " << piglatin(first) << " " << piglatin(last) << "." << endl;
}

int main(){

	e3();

	return 0;
}
/*
 * Output to console:
 *
Enter your first and last name and I shall convert your name to pig-latin!
Joseph Mosalem
Your name in pig-latin is Osephjay Osalemmay.
 */
