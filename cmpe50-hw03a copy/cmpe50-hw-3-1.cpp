//============================================================================
// Name        : cmpe50-hw-3-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : _______
// Date        : March 01, 2022
//============================================================================

#include <fstream>
#include <iostream>
using namespace std;

double avg(double arr[], int size){
	double total=0;
	for(int i=0; i<size; i++){
		total += arr[i];
	}
	return total/size;
}

void e1(string file){
	int count=0, autosize=50;
	double darr[autosize];
	ifstream infile (file);
	if(infile.is_open()){
		for (int i=0; i<autosize; i++){
			if(infile){
				infile >> darr[i];
				count++;
			}
		}
	} else {
		cout << "File could not be opened." << endl;
	}

	cout << "Average of the numbers in the file " << file << " is " << avg(darr, count) << endl;
}

string createTestTextFile(){
	ofstream outfile ("cmpe50-hw-3-1-test.txt");
	if(outfile.is_open()){
		outfile <<  "4.3 5.2 9.34 2.02\n3.0 4.7\n3.3\n5.009 6.57 5.55 0.12 1.324";
	} else {
		cout << "Unable to create file" << endl;
	}

	return "cmpe50-hw-3-1-test.txt";
}

int main(){

	e1(createTestTextFile());


	return 0;
}
/*
 * Output to console:
 *
Average of the numbers in the file cmpe50-hw-3-1-test.txt is 3.87946
 */
