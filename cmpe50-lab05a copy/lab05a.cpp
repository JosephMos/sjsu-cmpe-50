//============================================================================
// Name        : lab05a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : messing with c-strings and the string class [SCRAPPED]
// Date        : March 08, 2022
//============================================================================

/*
 * I GAVE UP ON THIS FILE
 * DONT TURN IN THIS FILE
 * INSTEAD, TURN IN 'cmpe50-lab05b.lab05b.cpp'
 *
 * FOR THE GRADER:
 * IF I ACCIDENTALLY TURNED THIS ONE IN, ALONG WITH THE FILE NOTED ABOVE,
 * DO NOT GRADE THIS ONE.
 * THIS ONE WAS SCRAPPED.
 * GRADE THE OTHER ONE.
 */

#include <string>
#include <fstream>
#include <iostream>
using namespace std;



void e1(string inputfile){//working for file // broken for console input
	char arr[100];//up to 100 char is instructions
	int i=0;
	int decision=0;
	cout << "For exercise 1, would you like to use a file or input text via the console?\n(Enter 1 for file and 2 for console)" << endl;
	cin >> decision;

	if(decision == 1){//file input
		cout << "You have chose to input from a file. Pregenerating a file...\nDone\nTaking input from " << inputfile << endl;
		ifstream infile (inputfile);

		if (infile.is_open()) {
			while(i<100){
				infile >> std::noskipws >> arr[i];
				//cout << "i = " << i << ", and arr[i] = " << arr[i] << endl;//debugging
				if(i>0){
					if(arr[i] == ' ' && arr[i-1] == ' '){
						//don't increment i and thus skip the space
						arr[i]='\0';
					} else if(arr[i] == '\n'){
						arr[i] = ' ';
					} else{
						if(arr[i] != ' ' && arr[i-1] == ' '){
							arr[i] = toupper(arr[i]);
						} else {
							arr[i] = tolower(arr[i]);
						}
						i++;
					}
				} else {
					if(arr[i] != ' '){
						arr[i] = toupper(arr[i]);
						i++;
					}
				}
				if(arr[i] == '.'){
					break;
				}
			}
		}else {
			cout << "Unable to open file " << inputfile << endl;
		}
	} else if(decision == 2){//keyboard input
		int k=0;
		char arr2[100];
		cout << "You have decided to input a sentence yourself via the console.\n(Be sure to end your sentence with a '.')" << endl;
		string cinput;
		bool run=true;
		while(run){
			cin >> cinput;
			for(int j=0; j<cinput.length(); j++){
				arr2[k+j]=cinput.at(j);
				if(arr2[k+j] == '.'){
					run=false;
					break;
				}
			}
			k+= cinput.length();

		}
		i=0;
		while(i<100){
			arr[i]=arr2[k];
			k++;
			//cout << "i = " << i << ", and arr[i] = " << arr[i] << endl;//debugging
			if(i>0){
				if(arr[i] == ' ' && arr[i-1] == ' '){
					//don't increment i and thus skip the space
					arr[i]='\0';
				} else if(arr[i] == '\n'){
					arr[i] = ' ';
				} else{
					if(arr[i] != ' ' && arr[i-1] == ' '){
						arr[i] = toupper(arr[i]);
					} else {
						arr[i] = tolower(arr[i]);
					}
					i++;
				}
			} else {
				if(arr[i] != ' '){
					arr[i] = toupper(arr[i]);
					i++;
				}
			}
			if(arr[i] == '.'){
				break;
			}
		}
	}

	for(int j=0; j<i; j++){
		cout << "" << arr[j];
	}
}

void e2(string inputfile){
	int decision=0;
	cout << "For exercise 2, would you like to use a file or input text via the console?\n(Enter 1 for file and 2 for console)" << endl;
	cin >> decision;

	if(decision == 1){//file input
		cout << "You have chose to input from a file. Pregenerating a file...\nDone\nTaking input from " << inputfile << endl;
		ifstream infile (inputfile);

		if (infile.is_open()) {

		}else {
			cout << "Unable to open file " << inputfile << endl;
		}
	} else if(decision == 2){//console input

	}
}

string createTestTextFile(int exercisenum){//idk if exercise 2 needs one, but just in case
	string filename;
	if(exercisenum == 1){
		filename = "LabInput5-1.txt";
		ofstream outfile (filename);
		if(outfile.is_open()){
			outfile <<  "   noW  iS   thE    TiMe  fOr  aLl \n";
			outfile <<  "         gOOD MEN TO  ComE TO   tHe \n";
			outfile <<  "  aId \n";
			outfile << "oF \n";
			outfile << "\n\n\n";
			outfile <<  "   ThE  CounTRY.";
			outfile.close();
		} else {
			cout << "Unable to create file" << endl;
		}
	} else if(exercisenum == 2){
		filename = "LabInput5-2.txt";
		ofstream outfile (filename);
		if(outfile.is_open()){
			outfile <<  "See an adviser, talk to him, and listen to him.";
			outfile.close();
		} else {
			cout << "Unable to create file" << endl;
		}
	}

	return filename;
}


int main(){

	e1(createTestTextFile(1));

	return 0;
}
/*
 * Output to console:
 *

 */
