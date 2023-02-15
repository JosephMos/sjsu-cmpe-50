//============================================================================
// Name        : cmpe50-hw-2-3.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : counts evens in an array
// Date        : February 20, 2022
//============================================================================

#include <iostream>
using namespace std;

void countEvens(int arr[], int size, int &evenCount){
	evenCount = 0;
	if(size == 0){
		return;
	}
	for(int i=0; i<size; i++){
		if(arr[i] %2 == 0){
			evenCount++;
		}
	}
	cout << "I counted " << evenCount << " evens in those " << size << " integers." << endl;
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

void driverProgram(int size, int &evencount){
	cout << "Enter " << size << " integers and I will count the number of even integers." << endl;
	int a[size];
	for(int i=0; i<size; i++){
		cin >> a[i];
	}
	cout << "You entered the values ";
	printArray(a, size);
	countEvens(a, size, evencount);
}

int main(){
	int s = 0;
	char yOrN = 'a';
	int evenCount=0;

	cout << "Would you like to countEvens()?" << endl;
	cout << "(Enter 'y' for yes, or 'n' for no)" << endl;

	while (true){
		cin >> yOrN;
		if(yOrN == 'n'){
			break;
		}
		cout << "Enter how a size: ";
		cin >> s;
		driverProgram(s, evenCount);

		s = 0;
		yOrN = 'a';
		evenCount=0;

		cout << "Would you like to countEvens() again?" << endl;
		cout << "(Enter 'y' for yes, or 'n' for no)" << endl;
	}

	cout << "\n\nThank you for using this program. \nGoodbye.\n(program has terminated)" << endl;

	return 0;
}
/*
 * Output to console:
 *
Would you like to countEvens()?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 5
Enter 5 integers and I will count the number of even integers.
1 2 3 4 5
You entered the values 1, 2, 3, 4, 5
I counted 2 evens in those 5 integers.
Would you like to countEvens() again?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 6
Enter 6 integers and I will count the number of even integers.
2
4
6
8
10
12
You entered the values 2, 4, 6, 8, 10, 12
I counted 6 evens in those 6 integers.
Would you like to countEvens() again?
(Enter 'y' for yes, or 'n' for no)
y
Enter how a size: 3
Enter 3 integers and I will count the number of even integers.
1 3 5
You entered the values 1, 3, 5
I counted 0 evens in those 3 integers.
Would you like to countEvens() again?
(Enter 'y' for yes, or 'n' for no)
n


Thank you for using this program.
Goodbye.
(program has terminated)

 */
