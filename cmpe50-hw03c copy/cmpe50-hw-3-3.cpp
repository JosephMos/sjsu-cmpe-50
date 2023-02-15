//============================================================================
// Name        : cmpe50-hw-3-3.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : better organize a file
// Date        : March 01, 2022
//============================================================================

#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

void e3(string file1, string file2){
	string str[3];
	double arr[3][5];
	ifstream infile (file1);
	if(infile.is_open()){
		for(int i=0; i<3; i++){
			infile >> str[i];
			for(int j=0; j<5; j++){
				infile >> arr[i][j];
			}
		}
	} else {
		cout << "Input file could not be opened" << endl;
	}

	ofstream outfile (file2);
	if(outfile.is_open()){
		//outfile << std::fixed;
		//outfile << std::setprecision(2);
		for(int i=0; i<3; i++){
			outfile << i+1 << ". ";
			outfile << left << setw(10) << str[i];
			for(int j=0; j<5; j++){
				outfile << right << setw(7) << fixed << setprecision(2) << arr[i][j];
			}
			outfile << " \n";
		}
	} else {
		cout << "Output file could not be created" << endl;
	}
}

string createTestTextFile(){
	ofstream outfile ("cmpe50-hw-3-3-1-test.txt");
	if(outfile.is_open()){
		outfile <<  "   Jones   80.5     77   95.7    88.6   100 \n";
		outfile <<  "      Smith    80    99    100    87.8              93.76 \n";
		outfile <<  " Holmes 53.65      84.54   76.67   97.75   89.9 \n";
	} else {
		cout << "Unable to create file" << endl;
	}

	return "cmpe50-hw-3-3-1-test.txt";
}

int main(){

	e3(createTestTextFile(), "cmpe50-hw-3-3-2-test.txt");

	return 0;
}
/*
 * Output to file:
 *
1. Jones       80.50  77.00  95.70  88.60 100.00
2. Smith       80.00  99.00 100.00  87.80  93.76
3. Holmes      53.65  84.54  76.67  97.75  89.90
 */
