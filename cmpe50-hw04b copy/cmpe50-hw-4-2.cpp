//============================================================================
// Name        : cmpe50-hw-4-2.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : word and letter count
// Date        : March 08, 2022
//============================================================================

#include <iostream>
using namespace std;

bool isletter(char c){
	return !(c == ' ' || c == '\n' || c == '\0' || c == '.' || c == ',');
}

void e2(){//works
	int wordcount=0, lettercount=0;
	string str;
	cout << "Enter a sentence and I will return the number of words and letters respectively." << endl;
	getline(cin, str);
	if(str.length() > 0){
		if(str.length() == 1){
			if(isletter(str.at(0))){
				wordcount++;
				lettercount++;
			}
		} else { //is str.length() is atleast 2 char's
			if(isletter(str.at(0))){
				wordcount++;
				lettercount++;
			}
			for(int i=1; i<str.length(); i++){
				if(isletter(str.at(i))){
					lettercount++;
					if(!isletter(str.at(i-1))){
						wordcount++;
					}
				}//
			}
		}
	} else {
		wordcount = 0;
		lettercount = 0;
	}

	cout << "You input " << wordcount << " words and " << lettercount << " letters." << endl;
}

int main(){

	e2();

	return 0;
}
/*
 * Output to console:
 *
Enter a sentence and I will return the number of words and letters respectively.
This is a sentence.
You input 4 words and 15 letters.

 */
