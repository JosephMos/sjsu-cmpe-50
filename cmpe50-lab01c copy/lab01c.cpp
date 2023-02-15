//============================================================================
// Name        : lab01c.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : a ^ b
// Date        : February 01, 2022
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int a, b;

	cout << "enter 2 integers" << endl;
	cin >> a;
	cin >> b;

	int c = pow(a, b);
	cout << a << " raised to the power of " << b << " = " << c << endl;

	return 0;
}

/*
 * The output to console:
 *
enter 2 integers
2
3
2 raised to the power of 3 = 8
 */
