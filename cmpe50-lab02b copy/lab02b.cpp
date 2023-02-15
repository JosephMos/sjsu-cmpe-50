//============================================================================
// Name        : lab02b.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : Reverse input string of characters
// Date        : February 08, 2022
//============================================================================

#include <array>
#include <iostream>
using namespace std;

int main() {

	int n = 0, strend;
	cout << "Enter how many characters you wish to enter:" << endl;
	cin >> n;

	char str[n];

		for(int i = 0; i<n; i++){
			cout << "Enter character number " << i+1 << ":" << endl;
			cout << "(Enter '.' to end the character)" << endl;
			cin >> str[i];
			strend = i;
			if(str[i] == '.'){
				break;
			}
		}

//cout << str << endl;
	//if(sizeof(str))

	for(int i=strend; i>=0; i--){
		if(str[i] != '.'){
			cout << str[i];
		}
	}


	return 0;
}

/*
 * The output to console:
 *
Enter how many characters you wish to enter:
6
Enter character number 1:
(Enter '.' to end the character)
a
Enter character number 2:
(Enter '.' to end the character)
b
Enter character number 3:
(Enter '.' to end the character)
c
Enter character number 4:
(Enter '.' to end the character)
d
Enter character number 5:
(Enter '.' to end the character)
.
dcba
 */

