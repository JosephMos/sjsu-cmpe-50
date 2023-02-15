//============================================================================
// Name        : cmpe50-hw-1-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : calculate clothing sizes based off body proportions
// Date        : February 13, 2022
//============================================================================

#include <iomanip>
#include <iostream>
using namespace std;

void hatSize(int h, int w){//print value
	float toReturn;
	toReturn = ((float)w/(float)h)*2.9;

	cout << "Your Hat Size is: " << (int)toReturn << "." << endl;
}

void jacketSize(int h, int w, int a){//print value
	float toReturn;
	toReturn = (((float)h*(float)w)/288);
	if(a>=40 && a%10==0){
		toReturn += (1/8)*((a-30)/10);
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "Your Jacket Size is: " << toReturn << " inches." << endl;
}

void waist(int w, int a){//print value
	float toReturn;
	toReturn = ((float)w/5.7);
	if(a>=30 && a%2==0){
		toReturn += 0.1*((a-28)/2);
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "Your Waist Size is: " << toReturn << " inches." << endl;
}

int main() {
	int height=0, weight=0, age=0;
	int choice=0; //1 for hat, 2 for jacket, 3 for waist, 4 to quit
	cout << "Enter your height in inches (ex: 5 ft 4 in should be entered as 64):" << endl;
	cin >> height;
	cout << "Enter your weight in pounds:" << endl;
	cin >> weight;
	cout << "Enter your age:" << endl;
	cin >> age;

	cout << "Your height is " << height/12 << " feet " << height%12 << " inches." << endl;
	cout << "Your weight is " << weight << " pounds. " << endl;
	cout << "Your age is " << age << ". " << endl;

	while(choice != 4){
		cout << "What would you like to calculate?" << endl;
		cout << "(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)" << endl;
		cin >> choice;

		switch(choice) {
			case 1: //hat size
				hatSize(height, weight);
				choice = 0;
				break;
			case 2: //jacket size
				jacketSize(height, weight, age);
				choice = 0;
				break;
			case 3:
				waist(weight, age);
				choice = 0;
				break;
		}
	}
	cout << "Program has ended." << endl;

	return 0;
	/*
	 * Output to console:

Enter your height in inches (ex: 5 ft 4 in should be entered as 64):
72
Enter your weight in pounds:
135
Enter your age:
18
Your height is 6 feet 0 inches.
Your weight is 135 pounds.
Your age is 18.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
1
Your Hat Size is: 5.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
2
Your Jacket Size is: 33.75 inches.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
3
Your Waist Size is: 23.68 inches.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
1
Your Hat Size is: 5.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
3
Your Waist Size is: 23.68 inches.
What would you like to calculate?
(enter 1 for hat size, 2 for jacket size, 3 for waist, or 4 to quit)
4
Program has ended.
	 */
}


