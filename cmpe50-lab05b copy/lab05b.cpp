//============================================================================
// Name        : lab05a.cpp
// Author      : Joseph Mosalem
// Version     : v2.0 (because I made mistakes on v1.0, but wanted to keep what I did)
// Copyright   : Your copyright notice
// Description : messing with c-strings and the string class
// Date        : March 08, 2022
//============================================================================

#include <string>
#include <iostream>
using namespace std;

void e1(){//working
	cout << "This is exercise 1:\n" << endl;

	//here begins the code for e1
	string strinput, totalStrinput;
	bool run=true;
	cout << "Enter a sentence and I will fix it.\n(Be sure to end the sentence with a '.')" << endl;
	while(run){
		cin >> strinput;
		totalStrinput += " " + strinput;
		size_t found = totalStrinput.find(".");
		if(found!=std::string::npos){
			run=false;
		}
	}
	if(totalStrinput.length() >0){
		if(totalStrinput.at(0) == ' '){//gets rid of space at start
			totalStrinput.erase(totalStrinput.begin(), totalStrinput.begin()+1);
		}
		if(totalStrinput.at(totalStrinput.length()-2) == ' '){//gets rid of space at end before '.'
			totalStrinput.erase(totalStrinput.length()-2);
			totalStrinput += ".";
		}
		for(int i=0; i<totalStrinput.length(); i++){
			totalStrinput.at(i) = tolower(totalStrinput.at(i));
		}
		totalStrinput.at(0) = toupper(totalStrinput.at(0));
		for(int i=1; i<totalStrinput.length(); i++){
			if(totalStrinput.at(i-1) == ' '){
				totalStrinput.at(i) = toupper(totalStrinput.at(i));
			}
		}
	}

	cout << totalStrinput << "\n---------------E1 has ended---------------\n" << endl;
}

bool isletter(char c){
	return(c <=122 && c>=97);
}

string replacementgen(string input){
	if(input.compare("he")==0 || input.compare("she")==0){
		return "she or he";
	} else if(input.compare("him")==0 || input.compare("her")==0){
		return "her or him";
	} else if(input.compare("his")==0 || input.compare("her")==0 || input.compare("hers")==0){
		return "her(s) or his";
	} else {
		return input;
	}//shortest replacement is 9 letters
}

void e2(){
	cout << "This is exercise 2:\n" << endl;

	//here begins the code for e2
	string str, word="";
	bool again = true;

	while(again){
		cout << "Enter a sentence" << endl;

		getline(cin, str);
		//cout << "got to here";
		for(int i=0; i<str.length(); i++){
			//cout << "str length = " << str.length() << " and i = " << i << " and str reads " << str << endl;
			//cout << "word reads " << word << endl;
			str.at(i) = tolower(str.at(i));
			if(isletter(str.at(i))){
				word+=str.at(i);
			} else {//if not a letter
				if(word.compare(replacementgen(word)) != 0){//if not equal, means can be replaced
					str.replace(i-word.length(), word.length(), replacementgen(word));
					i+= replacementgen(word).length() -1;
				}//else just skip and keep going
				word = "";
			}
		}
		str.at(0) = toupper(str.at(0));
		cout << str << endl;
		str="";

		cout << "Would you like to enter another sentence?\n(Enter 1 for yes and 0 for no)" << endl;
		cin >> again;
		cin.ignore();
	}

	cout << str << "\n---------------E2 has ended---------------\n" << endl;
}

int main(){

	e1();
	e2();

	return 0;
}
/*
 * Output to console:
 *
This is exercise 2:

Enter a sentence
See an adviser, talk to him, and listen to him.
See an adviser, talk to her or him, and listen to her or him.
Would you like to enter another sentence?
(Enter 1 for yes and 0 for no)
1
Enter a sentence
See an adviser, talk to she, and listen to his.
See an adviser, talk to she or he, and listen to her(s) or his.
Would you like to enter another sentence?
(Enter 1 for yes and 0 for no)
0

---------------E2 has ended---------------


 */
