//============================================================================
// Name        : lab07a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : how to make friends (a sorely needed lab lol jk i have friends)
// Date        : April 05, 2022
//============================================================================

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Resource { //e1 done
private:
	//variables
	int status; // = either 1 or 0
	int writeTo; // = either 1 or 0

public:
	//constructors
	Resource() {
		status = 0;
		writeTo = 0;
	}
	Resource(int w) {
		writeTo = w;
		if (w > 1) {
			writeTo = 1;
		}
		status = writeTo;
	}

	//setters
//	void setStatus(int s) {
//		status = s;
//		if(s>1){
//			status = 1;
//		}
//	}
	void setWriteTo(int w) {
		writeTo = w;
		if (w > 1) {
			writeTo = 1;
		}
		status = writeTo;
	}

	//getters
	int getStatus() {
		return status;
	}
	int getWriteTo() {
		return writeTo;
	}

	//other
	void output(ostream &out_stream) {
		out_stream << "Resource Status: " << status << endl;
	}

	friend bool check_status(Resource &res1, Resource &res2);

	/* last thing:
	 A friend function check_status that accesses the status variables of two
	 input objects.  If status in each resource object is set to “1”, display
	 “resource available” else display “resource unavailable”.

	 bool check_status(Resource &res1, Resource &res2)
	 {
	 // Define status checking code here.
	 // return true if res1 status and res2 status are both 1
	 // else return false.
	 }
	 */
};

bool check_status(Resource &res1, Resource &res2) {
	if (res1.status == 1) {
		cout << "Resource 1 available. ";
	} else {
		cout << "Resource 1 unavailable. ";
	}
	if (res2.status == 1) {
		cout << "Resource 2 available. " << endl;
	} else {
		cout << "Resource 2 unavailable. " << endl;
	}
	return (res1.status == 1 && res2.status == 1);
}

class Rational { //e2 done
private:
	//variables
	int numerator;
	int denominator;

public:
	//constructor
	Rational() {
		numerator = 1;
		denominator = 1;
	}
	Rational(int n, int d) {
		numerator = n;
		denominator = d;
	}

	//getter
	int getNumerator() {
		return numerator;
	}
	int getDenominator() {
		return denominator;
	}

	//setter
	void setNumerator(int n) {
		numerator = n;
	}
	void setDenominator(int d) {
		denominator = d;
	}

	//other
	void input(istream &in_stream) { //how does the info come in? assume int x, int y. 'x/y'
		string str;
		in_stream >> str;
		stringstream ss, ss2;
		ss << str.substr(0, str.find("/"));
		ss >> numerator;
		ss2 << str.substr(str.find("/") + 1);
		ss2 >> denominator;
		//maybe theres an easier way? idk
	}

	void output(ostream &out_stream) {
		out_stream << numerator << "/" << denominator << endl;
	}

	//friend
	friend Rational add(Rational &r1, Rational &r2);
	friend Rational subtract(Rational &r1, Rational &r2);
	friend Rational multiply(Rational &r1, Rational &r2);
	friend Rational divide(Rational &r1, Rational &r2);
	friend bool less_than(Rational &r1, Rational &r2);
	friend bool equal(Rational &r1, Rational &r2);
};

//helper functions:
int positizinator(int num) {
	if (num < 0) {
		return num * -1;
	}
	return num;
}

int gcd(int n1, int n2) {
	int gcd = 0, temp = 0;
	if (n2 > n1) {
		temp = n2;
	} else {
		temp = n1;
	}

	for (int i = 1; i <= temp; ++i) {
		if (n1 % i == 0 && n2 % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}

void rationalNormalizer(int &n, int &d) {
	if (n < 0) {
		n *= -1;
		d *= -1;
	}
	int hcf = 0; //hcf (highest common factor) and gcd are the same thing. idk why but it had an issue when i put 'gcd' instead of 'hcf'
	hcf = gcd(positizinator(n), positizinator(d));
	n = n / hcf;
	d = d / hcf;
}
//end helper functions

//friend functions:
Rational add(Rational &r1, Rational &r2) { // a/b + c/d = (ad + cb)/bd
	int n = r1.getNumerator() * r2.getDenominator()
			+ r2.getNumerator() * r1.getDenominator();
	int d = r1.getDenominator() * r2.getDenominator();
	rationalNormalizer(n, d);
	Rational added(n, d);
	return added;
}

Rational subtract(Rational &r1, Rational &r2) { // a/b - c/d = (ad - cb)/bd
	int n = r1.getNumerator() * r2.getDenominator()
			- r2.getNumerator() * r1.getDenominator();
	int d = r1.getDenominator() * r2.getDenominator();
	rationalNormalizer(n, d);
	Rational subtracted(n, d);
	return subtracted;
}

Rational multiply(Rational &r1, Rational &r2) { // a/b * c/d = (a*c)/(b*d)
	int n = r1.getNumerator() * r2.getNumerator();
	int d = r1.getDenominator() * r2.getDenominator();
	rationalNormalizer(n, d);
	Rational multiplied(n, d);
	return multiplied;
}

Rational divide(Rational &r1, Rational &r2) { // a/b / c/d = a/b * d/c = (a*d)/(b*c)
	int n = r1.getNumerator() * r2.getDenominator();
	int d = r1.getDenominator() * r2.getNumerator();
	rationalNormalizer(n, d);
	Rational divided(n, d);
	return divided;
}

bool less_than(Rational &r1, Rational &r2) { // a/b < c/d if (a*d) < (c*b)
	int n = r1.getNumerator() * r2.getDenominator();
	int d = r1.getDenominator() * r2.getNumerator();
	return (n < d);
}

bool equal(Rational &r1, Rational &r2) { // a/b == c/d if (a*d) == (c*b)
	int n = r1.getNumerator() * r2.getDenominator();
	int d = r1.getDenominator() * r2.getNumerator();
	return (n == d);
}
//end friend functions

//tester functions
void e1() {
	Resource res1, r;
	Resource res2(1);
	res1.setWriteTo(1);
	cout << "Res1 WriteTo = " << res1.getWriteTo() << ", Status = "
			<< res1.getStatus() << endl;
	res2.output(cout);
	cout << check_status(res1, res2);
}

void e2() {
	Rational r1, ra, rs, rm, rd;
	Rational r2(1, 2); // 1/2
	cout << "Enter a rational number in the form x/y , where x and y are integers and y != 0. ";
	r1.input(cin);
	cout << "r1 = ";
	r1.output(cout);
	cout << "r2 = ";
	r2.output(cout);

	ra = add(r1, r2);
	rs = subtract(r1, r2);
	rm = multiply(r1, r2);
	rd = divide(r1, r2);
	cout << "r1 + r2 = ";
	ra.output(cout);
	cout << "r1 - r2 = ";
	rs.output(cout);
	cout << "r1 * r2 = ";
	rm.output(cout);
	cout << "r1 / r2 = ";
	rd.output(cout);

	cout << "If r1 is less than r2, it will print 1. else 0. : "
			<< less_than(r1, r2) << endl;
	cout << "If r1 is equal to r2, it will print 1. else 0. : " << equal(r1, r2)
			<< endl;
}
//end tester functions

int main() {

	e1();
	e2();

	return 0;
}
/*
 * Output to console:
 *e1:
 Res1 WriteTo = 1, Status = 1
 Resource Status: 1
 Resource 1 available. Resource 2 available.
 1

 *e2:
 Rational r1, ra, rs, rm, rd;
 Rational r2(1, 2); // 1/2
 cout << "Enter a rational number in the form x/y , where x and y are integers and y != 0. ";
 r1.input(cin);
 cout << "r1 = ";
 r1.output(cout);
 cout << "r2 = ";
 r2.output(cout);

 ra = add(r1, r2);
 rs = subtract(r1, r2);
 rm = multiply(r1, r2);
 rd = divide(r1, r2);
 cout << "r1 + r2 = ";
 ra.output(cout);
 cout << "r1 - r2 = ";
 rs.output(cout);
 cout << "r1 * r2 = ";
 rm.output(cout);
 cout << "r1 / r2 = ";
 rd.output(cout);

 cout << "If r1 is less than r2, it will print 1. else 0. : " << less_than(r1, r2) << endl;
 cout << "If r1 is equal to r2, it will print 1. else 0. : " << equal(r1, r2) << endl;
 */
