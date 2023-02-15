//============================================================================
// Name        : lab06a.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : messing with classes
// Date        : March 14, 2022
//============================================================================

#include <iostream>
using namespace std;

class StudentRecord {//for e1
private:
	int quiz[3];
	int midterm;
	int final;
	double weightedAverage;

public:
	//constructors
	StudentRecord(){
		//quiz; //can i get away with this b/c its initialized as {0,0,0}?
		midterm=0;
		final=0;
		weightedAverage=0;
	}
	StudentRecord(int q[], int mid, int fin){
		for(int i=0; i<3;i++){
			this->quiz[i] = q[i];
		}
		this->midterm=mid;
		this->final=fin;
		setWeightedAverage();
	}

	//setters
	void setQuiz(int q[]){
		for(int i=0; i<3;i++){
			this->quiz[i] = q[i];
		}
	}
	void setQuiz1(int q1){
		this->quiz[0] = q1;
	}
	void setQuiz2(int q2){
		this->quiz[1] = q2;
	}
	void setQuiz3(int q3){
		this->quiz[2] = q3;
	}
	void setMidterm(int m){
		this->midterm = m;
	}
	void setFinal(int f){
		this->final = f;
	}
	void setWeightedAverage(){
		if(quiz[0]<quiz[1] && quiz[0] < quiz[2]){//1 and 2 are best 2 quiz
			weightedAverage= (double)((((((double)quiz[1] + (double)quiz[2])/20) * 0.25) + (((double)midterm / 100) * 0.25) + (((double)final / 100) * 0.5)) * 100);
		} else if (quiz[1]<quiz[0] && quiz[1] < quiz[2]){// 0 and 2 are best 2 quiz
			weightedAverage= (double)((((((double)quiz[0] + (double)quiz[2])/20) * 0.25) + (((double)midterm / 100) * 0.25) + (((double)final / 100) * 0.5)) * 100);
		} else {//0 and 1 are best 2
			weightedAverage= (double)((((((double)quiz[1] + (double)quiz[0])/20) * 0.25) + (((double)midterm / 100) * 0.25) + (((double)final / 100) * 0.5)) * 100);
		}
	}

	//getters
	int getQuiz1(){
		return this->quiz[0];
	}
	int getQuiz2(){
		return this->quiz[1];
	}
	int getQuiz3(){
		return this->quiz[2];
	}
	int getMidterm(){
		return this->midterm;
	}
	int getFinal(){
		return this->final;
	}
	double getWeightedAverage(){
		return this->weightedAverage;
	}


};

class Counter {//for e2
private:
	int counterVar;
	int count;
	void correctIfNeg(){
		if(counterVar <0){
			cout << "Counter cannot be less than 0.\nSetting to 0 (lower limit)." << endl;
			counterVar = 0;
		}
	}

public:
	//constructors
	Counter(){
		counterVar=0;
	}
	Counter(int count){
		this->counterVar = count;
		correctIfNeg();
	}

	//setters
	void setCounter(int count){
		this->counterVar = count;
		correctIfNeg();
	}

	//getters
	int getCounter(){
		return counterVar;
	}

	//inc and dec
	void increaseCounter(){
		counterVar++;
		correctIfNeg();
	}
	void decreaseCounter(){
		counterVar--;
		correctIfNeg();
	}

	//print
	void printCounter(){
		cout << getCounter();
	}
};

class Parallelogram{//for e3
private:
	double base;
	double height;
	double area;

public:
	//constructor
	Parallelogram(){
		base=0;
		height=0;
		area=0;
	}
	Parallelogram(double b, double h){
		base = b;
		height = b;
		calculateArea();
	}
	Parallelogram(int b, int h){
		base = (double)(b);
		height = (double)(h);
		calculateArea();
	}

	//setters
	void setBase(double b){
		base=b;
	}
	void setBase(int b){
		base = (double)(b);
	}
	void setHeight(double h){
		height = h;
	}
	void setHeight(int h){
		height = (double)(h);
	}

	//getters
	double getBase(){
		return base;
	}
	double getHeight(){
		return height;
	}

	//calculate
	void calculateArea(){
		this->area = (double)(base*height);
	}

	//display
	void display(){
		calculateArea();
		cout << area;
	}

};

void e1tester(){
	cout << "e1tester() begin: \n" << endl;
	int quiz[3];
	int midterm=0, fin=0;
	cout << "Enter 3 quiz grades (out of 10 each)" <<endl;
	cin >> quiz[0] >> quiz[1] >> quiz[2];
	if(quiz[0] > 10){
		quiz[0] = 10;
	}
	if(quiz[1] > 10){
		quiz[1] = 10;
	}
	if(quiz[2] > 10){
		quiz[2] = 10;
	}
	cout << "Enter a midterm grade (out of 100)" << endl;
	cin >> midterm;
	if(midterm>100){
		midterm = 100;
	}
	cout << "Enter a final grade (out of 100)" << endl;
	cin >> fin;
	if(fin>100){
		fin=100;
	}
	StudentRecord record(quiz, midterm, fin);
	cout << "The weighted average is " << record.getWeightedAverage() << endl;

	//debugging
	//cout << "quiz scores: " << record.getQuiz1() << " " << record.getQuiz2() << " " << record.getQuiz3() << " midterm: " <<  record.getMidterm() << " final: " << record.getFinal();

	cout << "\ne1tester() end\n==================================\n" << endl;
}

void e2tester(){
	cout << "e2tester() begin: \n" << endl;

	cout << "Constructing counter with value -3" << endl;
	Counter c(-3);
	cout << "\nDecreasing counter by 1\n";
	c.decreaseCounter();
	cout << "\nSetting counter value to 4\n";
	c.setCounter(4);
	c.printCounter();
	cout << "\nIncreasing counter by 2\n";
	c.increaseCounter();
	c.increaseCounter();
	c.printCounter();


	cout << "\n\ne2tester() end\n==================================\n" << endl;
}

void e3tester(){
	cout << "e3tester() begin: \n" << endl;

	cout << "Enter a base and a height for your parallelogram.\n";
	int b, h;
	cin >> b >> h;
	Parallelogram par(b, h);
	par.calculateArea();
	cout << "area is ";
	par.display();

	cout << "\ne3tester() end\n==================================\n" << endl;
}

int main(){

	e1tester();
	e2tester();
	e3tester();

	return 0;
}
/*
 * Output to console:
 *
e1tester() begin:

Enter 3 quiz grades (out of 10 each)
9 9 1
Enter a midterm grade (out of 100)
98
Enter a final grade (out of 100)
300
The weighted average is 97

e1tester() end
==================================

e2tester() begin:

Constructing counter with value -3
Counter cannot be less than 0.
Setting to 0 (lower limit).

Decreasing counter by 1
Counter cannot be less than 0.
Setting to 0 (lower limit).

Setting counter value to 4
4
Increasing counter by 2
6

e2tester() end
==================================

e3tester() begin:

Enter a base and a height for your parallelogram.
4
6
area is 24
e3tester() end
==================================

 */
