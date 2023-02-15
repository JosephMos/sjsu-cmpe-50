//============================================================================
// Name        : cmpe50-hw-2-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : calculates avg and SD of 4 values
// Date        : February 17, 2022
//============================================================================

#include<cmath>
#include <iostream>
using namespace std;

void avgCalc(double num1, double num2, double num3, double num4, double &avgReturn){
	//void so just sets 'avgReturn' value to the usual returns value
	//when calling, pass the reference of where to store the avg as avgReturn

	avgReturn = (num1 + num2 + num3 + num4)/4;
}

void avgStdDev(double s1, double s2, double s3, double s4, double &average, double &stdDev){
	avgCalc(s1, s2, s3, s4, average);
	avgCalc(pow(s1-average, 2), pow(s2-average, 2), pow(s3-average, 2), pow(s4-average, 2), stdDev);
}

void resetValues(double &d1, double &d2, double &d3, double &d4, double &a, double &sDev, char &yn){
	d1=0;
	d2=0;
	d3=0;
	d4=0;
	a=0;
	sDev=0;
	yn = 'a';
}

void driverProgram(){
	//just a function to make main look clean
	char yOrN = 'a';
	double n1, n2, n3, n4;
	double avg=0, sD=0;

	cout << "Would you like to calculate the avg and SD of 4 numbers?" << endl;
	cout << "(Enter 'y' for yes, or 'n' for no)" << endl;

	while (true){
		cin >> yOrN;
		if(yOrN == 'n'){
			break;
		}
		cout << "Enter 4 numbers to calculate the avg and SD of:";
		cin >> n1 >> n2 >> n3 >> n4;
		cout << "You have entered the numbers: " << n1 << ", " << n2 << ", " << n3 << ", " << n4 << "." << endl;
		avgStdDev(n1, n2, n3, n4, avg, sD);
		cout << "the average is " << avg << " and the standard deviation is " << sD << endl;

		resetValues(n1, n2, n3, n4, avg, sD, yOrN);

		cout << "Would you like to calculate the avg and SD of 4 different numbers?" << endl;
		cout << "(Enter 'y' for yes, or 'n' for no)" << endl;
	}
	cout << "\n\nThank you for using this program. \nGoodbye.\n(program has terminated)" << endl;
}

int main(){

	driverProgram();

	return 0;
}
/*
 * Output to console:
 *
Would you like to calculate the avg and SD of 4 numbers?
(Enter 'y' for yes, or 'n' for no)
y
Enter 4 numbers to calculate the avg and SD of:2 3 4 5
You have entered the numbers: 2, 3, 4, 5.
the average is 3.5 and the standard deviation is 1.25
Would you like to calculate the avg and SD of 4 different numbers?
(Enter 'y' for yes, or 'n' for no)
y
Enter 4 numbers to calculate the avg and SD of:3
4
5
6
You have entered the numbers: 3, 4, 5, 6.
the average is 4.5 and the standard deviation is 1.25
Would you like to calculate the avg and SD of 4 different numbers?
(Enter 'y' for yes, or 'n' for no)
n


Thank you for using this program.
Goodbye.
(program has terminated)

 */
