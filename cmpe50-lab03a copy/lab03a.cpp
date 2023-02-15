//============================================================================
// Name        : lab03a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : check if student passes class
// Date        : February 08, 2022
//============================================================================

#include <iomanip>
#include <array>
#include <iostream>
using namespace std;

double findBestOrWorst(bool tForBest, double arr[][8], int rowNum){
	//if rowNum = 0, check hw row. if 1, check lab row
	int bestI=0, worstI=0;
	for(int i=1; i<5; i++){
		if(arr[rowNum][i] > arr[rowNum][bestI]){
			bestI=i;
		}
		if(arr[rowNum][i] < arr[rowNum][worstI]){
			worstI=i;
		}
	}
	if(tForBest){
		return arr[rowNum][bestI];
	} else {
		return arr[rowNum][worstI];
	}
	return 0;//should never reach this line
}

int main() {


	double grades[3][8];
	for (int i= 0; i < 2; i++){//row
		for (int j = 0; j< 5; j++){//col
			if(i == 0){//hw
				cout << "Enter HW grade percentage number " << j+1 << ":" << endl;
				cin >> grades[0][j];
				if(grades[0][j] > 100){
					grades[0][j] = 100;
				}
			}
			if(i == 1){//labs
				cout << "Enter Lab grade percentage number " << j+1 << ":" << endl;
				cin >> grades[1][j];
				if(grades[1][j]>100){
					grades[1][j] = 100;
				}
			}
		}
	}

	for(int i=0; i<5; i++){
		grades[2][i] = (grades[0][i] + grades[1][i])/2;//avg row (row 2)
	}
	grades[2][5] = (grades[2][0] + grades[2][1] + grades[2][2] + grades[2][3] + grades[2][4])/5;//overall

	//hw
	grades[0][5] = findBestOrWorst(true, grades, 0); //best
	grades[0][6] = findBestOrWorst(false, grades, 0); //worst
	grades[0][7] = (grades[0][0] + grades[0][1] + grades[0][2] + grades[0][3] + grades[0][4])/5; //avg

	//lab
	grades[1][5] = findBestOrWorst(true, grades, 1); //best
	grades[1][6] = findBestOrWorst(false, grades, 1); //worst
	grades[1][7] = (grades[1][0] + grades[1][1] + grades[1][2] + grades[1][3] + grades[1][4])/5; //avg

	//okay now i need to print
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	cout << "\n\n         1      2      3      4      5    BEST   WORST   AVG \n";
	cout << "     ******************************************************** \n";
	cout << "HW   "; //hw row begin
	for(int i=0; i<8; i++){
		if(grades[0][i] > 99.99){
			grades[0][i] = 100.00;
			cout << " 100.00";
		} else {
			if(grades[0][i] < 10){ cout << " ";}
			cout << "  " << grades[0][i];
		}
	}
	cout << "\n"; //lab row end
	cout << "LAB  "; //lab row begin
	for(int i=0; i<8; i++){
		if(grades[1][i] > 99.99){
			grades[1][i] = 100.00;
			cout << " 100.00";
		} else {
			if(grades[1][i] < 10){ cout << " ";}
			cout << "  " << grades[1][i];
		}
	}
	cout << "\n\n"; //lab row end
	cout << "AVG  "; //avg row begin
	for(int i=0; i<5; i++){
		if(grades[2][i] > 99.99){
			grades[2][i] = 100.00;
			cout << " 100.00";
		} else {
			if(grades[2][i] < 10){ cout << " ";}
			cout << "  " << grades[2][i];
		}
	}
	if ((int)grades[2][5] > 99){
		grades[2][5] = 100;
	}
	cout << "   Overall: " << (int)grades[2][5] << "\n\n"; //avg row end

	bool labPassed=true, hwPassed=true;


		if(grades[0][7] < 50){
			hwPassed = false;
		}
		if(grades[1][7] < 50){
			labPassed = false;
		}


	if(!hwPassed){
		if(!labPassed){
			//option 2: hw and lab
			cout << "I’m sorry to inform you that you failed the class, because your \nperformance in the HW and Lab was <50%. Try again next semester." << endl;
		} else {
			//option 2: hw
			cout << "I’m sorry to inform you that you failed the class, because your \nperformance in the HW was <50%. Try again next semester." << endl;
		}
	} else if(!labPassed){
		//option 2: lab
		cout << "I’m sorry to inform you that you failed the class, because your \nperformance in the Lab was <50%. Try again next semester." << endl;
	} else {//if both are true
		//option 1
		cout << "Congratulations! You passed the class!" << endl;
	}

	return 0;
}
/*
 * Output to console:
 *
Enter HW grade percentage number 1:
12
Enter HW grade percentage number 2:
32
Enter HW grade percentage number 3:
34
Enter HW grade percentage number 4:
54
Enter HW grade percentage number 5:
43
Enter Lab grade percentage number 1:
23
Enter Lab grade percentage number 2:
34
Enter Lab grade percentage number 3:
78
Enter Lab grade percentage number 4:
89
Enter Lab grade percentage number 5:
90


         1      2      3      4      5    BEST   WORST   AVG
     ********************************************************
HW     12.00  32.00  34.00  54.00  43.00  54.00  12.00  35.00
LAB    23.00  34.00  78.00  89.00  90.00  90.00  23.00  62.80

AVG    17.50  33.00  56.00  71.50  66.50   Overall: 48

I’m sorry to inform you that you failed the class, because your
performance in the HW was <50%. Try again next semester.

 */


