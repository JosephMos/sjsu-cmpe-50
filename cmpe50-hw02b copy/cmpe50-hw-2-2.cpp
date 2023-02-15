//============================================================================
// Name        : cmpe50-hw-2-2.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : swaps the first element of an array with the last element
// Date        : February 19, 2022
//============================================================================

#include <iostream>
using namespace std;

void swapFrontBack(int arr[], int size){//don't change these params; these were part of instructions
	int i=arr[size-1];
	arr[size-1] = arr[0];
	arr[0] = i;
}

void printArray(int arr[], int size){
	if(size == 0){
		return;
	} else if(size == 1){
		cout << arr[0] << endl;
	}
	cout << arr[0];
	for(int i=1; i<size; i++){
		cout << ", " << arr[i];
	}
	cout << endl;
}

void driverProgram(int size){
	cout << "Enter " << size << " integers and I will swap the first and last integer." << endl;
	int a[size];
	for(int i=0; i<size; i++){
		cin >> a[i];
	}
	cout << "You entered the values ";
	printArray(a, size);
	swapFrontBack(a, size);
	cout << "After swapping the first and last values, I present to you:" << endl;
	printArray(a, size);
}

int main(){
	int s = 0;
	char yOrN = 'a';

	cout << "Would you like to swapFrontBack()?" << endl;
	cout << "(Enter 'y' for yes, or 'n' for no)" << endl;

	while (true){
		cin >> yOrN;
		if(yOrN == 'n'){
			break;
		}
		cout << "Enter how a size: ";
		cin >> s;
		driverProgram(s);

		s = 0;
		yOrN = 'a';

		cout << "Would you like to swapFrontBack() again?" << endl;
		cout << "(Enter 'y' for yes, or 'n' for no)" << endl;
	}

	cout << "\n\nThank you for using this program. \nGoodbye.\n(program has terminated)" << endl;

	return 0;
}
/*
 * Output to console:
 *
Would you like to swapFrontBack()?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 5
Enter 5 integers and I will swap the first and last integer.
1
2
3
4
5
You entered the values 1, 2, 3, 4, 5
After swapping the first and last values, I present to you:
5, 2, 3, 4, 1
Would you like to swapFrontBack() again?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 3
Enter 3 integers and I will swap the first and last integer.
1 2 3
You entered the values 1, 2, 3
After swapping the first and last values, I present to you:
3, 2, 1
Would you like to swapFrontBack() again?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 4
Enter 4 integers and I will swap the first and last integer.
1 2
3
4
You entered the values 1, 2, 3, 4
After swapping the first and last values, I present to you:
4, 2, 3, 1
Would you like to swapFrontBack() again?
(Enter 'y' for yes, or 'n' for no)
n


Thank you for using this program.
Goodbye.
(program has terminated)

 */
