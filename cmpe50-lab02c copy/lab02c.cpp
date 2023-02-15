//============================================================================
// Name        : lab02c.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : return the second largest integer of 10 ints
// Date        : February 08, 2022
//============================================================================

#include <array>
#include <iostream>
using namespace std;

int main() {

	cout << "Enter 10 integers: " << endl;
	int nums[10];
	int largest=0, secondLargest=0;

	for(int i=0; i<10; i++){
		cin >> nums[i];

		if(nums[i] > largest){
			secondLargest = largest;
			largest = nums[i];
		} else if(nums[i] > secondLargest){
			secondLargest = nums[i];
		}
	}

	cout << "You input the 10 integers: ";
	for(int j=0; j<10; j++){
		cout << nums[j] << " ";
	}
	cout << endl;
	cout << "The second largest integer was: " << secondLargest << "." << endl;

	return 0;
}


/*
 * The output to console:
 *
Enter 10 integers:
1
3
2
4
3
5
4
6
6
5
You input the 10 integers: 1 3 2 4 3 5 4 6 6 5
The second largest integer was: 6.
 */
//I was unsure whether it was supposed to print 6 (since the second 6 can be the 2nd largest int), or 5
