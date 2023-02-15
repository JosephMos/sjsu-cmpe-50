//============================================================================
// Name        : cmpe50-hw-3-2.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : merge 2 txt files into one sorted txt file
// Date        : March 01, 2022
//============================================================================

#include <fstream>
#include <iostream>
using namespace std;

void e2(string file1, string file2, string file3){
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

string createTestTextFile1(){
	ofstream outfile ("cmpe50-hw-3-2-1-test.txt");
	if(outfile.is_open()){
		outfile <<  "0 2 2 4\n5\n9 11 23 23 44";
	} else {
		cout << "Unable to create file" << endl;
	}

	return "cmpe50-hw-3-2-1-test.txt";
}

string createTestTextFile2(){
	ofstream outfile ("cmpe50-hw-3-2-2-test.txt");
	if(outfile.is_open()){
		outfile <<  "2\n3\n3 4 7 8\n33";
	} else {
		cout << "Unable to create file" << endl;
	}

	return "cmpe50-hw-3-2-2-test.txt";
}

int main(){

	e2(createTestTextFile1(), createTestTextFile2(), "cmpe50-hw-3-2-3-test.txt");

	return 0;
}
/*
 * Output to text file:
 *
0 2 2 2 3 3 4 4 5 7 8 9 11 23 23 33
 */
