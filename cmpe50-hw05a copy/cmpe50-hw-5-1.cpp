//============================================================================
// Name        : cmpe50-hw-5-1.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : _______
// Date        : March 21, 2022
//============================================================================

#include <iostream>
using namespace std;

class CDAccount {
private:
	double balance;
	double initial_balance;
	double interest_rate;
	int term; //months until maturity

	void get_data(){
		double ratefraction = (double)((double)interest_rate/100);
		double interest = initial_balance * ratefraction * ((double)term/12);
		balance = initial_balance + interest;
	}

public:
	double get_balance(){
		get_data();
		return this->balance;
	}
	double get_initial_balance(){
		return this->initial_balance;
	}
	double get_interest_rate(){
		return this->interest_rate;
	}
	int get_term(){
		return this->term;
	}

	CDAccount(double i_b, double i_r, double t){
		balance = i_b;
		initial_balance = i_b;
		interest_rate = i_r;
		term = t;
	}

	CDAccount(){
		balance = 0;
		initial_balance = 0;
		interest_rate = 0;
		term = 0;
	}
};

void e1(){
	cout << "Enter a balance (USD), interest rate (%), and term (years)" << endl;;
	double bal, ir;
	int ter;
	cout << "Enter account balance ";
	cin >> bal;
	cout << "Enter account interest rate ";
	cin >> ir;
	cout << "Enter number of months until maturity \n(must be less than 12) ";
	cin >> ter;
	CDAccount acc(bal, ir, ter);
	cout.setf(ios::fixed);
	//cout.setf(ios:showpoint);
	cout.precision(2);
	cout << "When your CD matures in " << acc.get_term() << " months, \nit will have a balance of $" << acc.get_balance() << endl;
}

int main(){

	e1();

	return 0;
}
/*
 * Output to console:
 *
Enter a balance (USD), interest rate (%), and term (years)
Enter account balance 200
Enter account interest rate 30
Enter number of months until maturity
(must be less than 12) 5
When your CD matures in 5 months,
it will have a balance of $225.00
 */
