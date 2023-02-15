//============================================================================
// Name        : lab04a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : messing around with i/o streams
// Date        : March 01, 2022
//============================================================================

#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

/* just a joke:
 * Why do programmers use dark IDE themes?
 * because bugs are attracted to light
 *
 * also, the file is labled 'a', but this file alone contains all my code for this lab
 * anyway, heres my code:
 */

void e1(){
	char arr[1000];
	int i=0;
	ifstream infile ("LabInput4-1.txt");
	if (infile.is_open()) {
		while(i<1000){
			infile >> arr[i];

			if(arr[i] == '.' || arr[i]=='!' || arr[i]=='?'){
				//excludes thos ones by replacing them
				arr[i] = '\0';
			} else {
				arr[i] = toupper(arr[i]);
				i++;
			}

		}
		infile.close();
	} else {
		cout << "Unable to open input file";
	}

	ofstream outfile ("LabOutput4-1.txt");
	i=0;
	if (outfile.is_open()){
		while(arr[i]){
			outfile << arr[i];
			i++;
		}
		outfile.close();
	} else {
		cout << "Unable to open output file";
	}
}

void e2(){
	cout << "Would you like to enter integers via keyboard, or from a file?\n(Enter 0 for keyboard and 1 for file) ";
	bool fromFile=0;
	cin >> fromFile;
	int size=50;
	int inArr[size];
	if(fromFile){
		cout << "You chose to input integers from a file.\nEnter the name of the file you wish to read from: ";
		string fileName;
		cin >> fileName; //if you want this to work as intended, enter 'LabInput4-2.txt'
		size=6; ifstream infile (fileName);
		if (infile.is_open()) {
			int i=0;
			//int inArr[size];
			while(i<size){
				infile >> inArr[i];

				i++;
			}
			infile.close();
		} else {
			cout << "Unable to open input file";
		}
	} else {//from keyboard
		cout << "You chose to input integers from your keyboard.\nHow many integers would you like to enter? ";
		cin >> size;
		//int inArr[size];
		for (int i=0; i<size; i++){
			cout << "Enter integer number " << i+1 << ": ";
			cin >> inArr[i];
		}
	}
	//at this point, inArr[] has all input ints
	int n=0;
	int sortedArr[size], sortedCount[size];

	sort(inArr, inArr+size);
	sortedArr[0] = inArr[0];
	sortedCount[0] = 1;

	for(int i=1; i<size; i++){
		if(inArr[i]==sortedArr[n]){
			sortedCount[n]++;
		} else {
			n++;
			sortedArr[n] = inArr[i];
			sortedCount[n] = 1;
		}
	}

	cout << "N  Count" << endl;//"x    x\n"
	for(int i=n; i>=0; i--){
		cout << sortedArr[i] << "    " << sortedCount[i] << endl;
	}

	ofstream outfile ("LabOutput4-2.txt");
	if (outfile.is_open()){
		outfile << "N  Count" << "\n";
		for(int i=n; i>=0; i--){
			outfile << sortedArr[i] << "    " << sortedCount[i] << "\n";
		}
		outfile.close();
	} else {
		cout << "Unable to open output file";
	}
}

void e3helper(string file1, string file2, string file3){
	//take in ints from file1 and file2, then sort and output to file3 (output file)
	int count1=0, count2=0, autoSize=10;//change autosize idk
	int arr1[autoSize], arr2[autoSize];

	ifstream infile1 (file1);
	ifstream infile2 (file2);
	if(infile1.is_open() && infile2.is_open()){
		for(int i=0; i<autoSize; i++){
			if(infile1){//if this doesnt work, the 'infile' is likely the issue
				infile1 >> arr1[i];
				count1++;
			} else {i=autoSize;}
		}
		for(int i=0; i<autoSize; i++){
			if(infile2){//if this doesnt work, the 'infile' is likely the issue
				infile2 >> arr2[i];
				count2++;
			} else {i=autoSize;}
		}
		infile1.close();
		infile2.close();
	} else {
		cout << "Unable to open file" << endl;
	}

	count1--; count2--;//for some reason this is wack?

	//cout << arr1[count1-1] << " " << arr2[count2-1] << " ; " << count1 << " " << count2 << " ; ";//debugging

	int outArr[count1+count2+2];
	for(int i=0; i<count1; i++){
		outArr[i]=arr1[i];
	}
	for(int i=0; i<count2; i++){
		outArr[i+count1]=arr2[i];
	}
	sort(outArr, outArr+count1+count2);

	ofstream outfile (file3);
	if(outfile.is_open()){
		for(int i=0; i<(count1+count2); i++){
			outfile << outArr[i] << " ";
			//cout << outArr[i] << " ";//debugging
		}
	} else {
		cout << "Unable to open file" << endl;
	}
}

void e3(){
	e3helper("LabInput4-3.txt", "LabInput4-4.txt", "LabOutput4-3.txt");
}

int main(){

	e1();
	e2();
	e3();

	return 0;
}
/*
 * Output to console:
 *
Would you like to enter integers via keyboard, or from a file?
(Enter 0 for keyboard and 1 for file) 1
You chose to input integers from a file.
Enter the name of the file you wish to read from: LabInput4-2.txt
N  Count
4    2
3    1
1    2
-3    1
 *
 *
 * Output to text file 'LabOutput4-1.txt'
 *
THISISASAMPLETESTDATAFILE
 *
 *
 * Output to text file 'LabOutput4-2.txt'
 *
N  Count
4    2
3    1
1    2
-3    1
 *
 *
 * Output to text file 'LabOutput4-3.txt'
 *
6 10 15 22 30 33 40 50 60 62 77 88 89 99
 */
