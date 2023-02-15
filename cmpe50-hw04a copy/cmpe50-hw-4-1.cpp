//============================================================================
// Name        : cmpe50-hw-4-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : count the number of lines from a file
// Date        : March 08, 2022
//============================================================================

#include <fstream>
#include <iostream>
using namespace std;

void e1(string input){
	char arr[1000];
	int linenum=0;
	cout << "...Pre-generating sample file...\n...Calculating...\n\n" << endl;

	ifstream infile (input);
	if(infile.is_open()){
		for(int i=0; i<1000; i++){
			infile >> noskipws >> arr[i];
			if(arr[i] == '\0'){
				break;
			}
			if(i>0 && arr[i-1] == '\n'){
				linenum++;
				cout << right << setw(3) << linenum << ": ";
			}
			if(i==0){
				linenum++;
				cout << right << setw(3) << linenum << ": ";
			}
			//if(arr[i+1] != '\0'){
				cout << arr[i];
			//}

		}
	} else {
		cout << "ERROR: Something went wrong when trying to open input file\n--program end--" << endl;
	}
}

string createTestTextFile(){
	string filename = "cmpe50-hw-4-1-input.txt";
	ofstream outfile (filename);
	if(outfile.is_open()){
		outfile <<  "With three or four    loggerheads amongst three or four  \n";
		outfile <<  "score   hogsheads.     I have sounded     the very  \n";
		outfile <<  "  base-string of humility.  Sirrah,   I am   sworn brother  \n";
		outfile <<  "to a leash of drawers;    and can call them all by  \n";
		outfile <<  "their christen names, as Tom,    Dick, and Francis.  \n";
		outfile <<  "  They take it already upon       their salvation, that  \n";
		outfile <<  "though I be but the prince of    Wales, yet I am king  \n";
		outfile <<  "of   courtesy; and tell me flatly I am no proud   Jack,  \n";
		outfile <<  "   like Falstaff, but a    Corinthian, a lad of mettle, a  \n";
		outfile <<  "good boy, by the Lord, so they call me,   and when I  \n";
		outfile <<  "am king of    England, I shall    command all the good  \n";
		outfile <<  "lads in Eastcheap.   \n";
	} else {
		cout << "Unable to create file" << endl;
	}

	return filename;
}

int main(){

	e1(createTestTextFile());

	return 0;
}
/*
 * Output to console:
 *
...Pre-generating sample file...
...Calculating...


  1: With three or four    loggerheads amongst three or four
  2: score   hogsheads.     I have sounded     the very
  3:   base-string of humility.  Sirrah,   I am   sworn brother
  4: to a leash of drawers;    and can call them all by
  5: their christen names, as Tom,    Dick, and Francis.
  6:   They take it already upon       their salvation, that
  7: though I be but the prince of    Wales, yet I am king
  8: of   courtesy; and tell me flatly I am no proud   Jack,
  9:    like Falstaff, but a    Corinthian, a lad of mettle, a
 10: good boy, by the Lord, so they call me,   and when I
 11: am king of    England, I shall    command all the good
 12: lads in Eastcheap.

 */
