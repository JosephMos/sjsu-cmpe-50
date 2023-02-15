//============================================================================
// Name        : cmpe50-hw-5-2.cpp
// Author      : Joseph Mosalem
// Version     :
// Copyright   : Your copyright notice
// Description : _______
// Date        : March 21, 2022
//============================================================================

#include <iostream>
using namespace std;

class month {
private:
	int mint;

	void calc_month(string s){
		if(s.at(0) == 'j'){
			if(s.at(1) == 'a'){
				if(s.at(2) == 'n'){
					mint=1;
				}
			}
			if(s.at(1) == 'u'){
				if(s.at(2) == 'n'){
					mint=6;
				}
				if(s.at(2) == 'l'){
					mint=7;
				}
			}
		}
		if(s.at(0) == 'f'){
			if(s.at(1) == 'e'){
				if(s.at(2) == 'b'){
					mint=2;
				}
			}
		}
		if(s.at(0) == 'm'){
			if(s.at(1) == 'a'){
				if(s.at(2) == 'r'){
					mint=3;
				}
				if(s.at(2) == 'y'){
					mint=5;
				}
			}
		}
		if(s.at(0) == 'a'){
			if(s.at(1) == 'p'){
				if(s.at(2) == 'r'){
					mint=4;
				}
			}
			if(s.at(1) == 'u'){
				if(s.at(2) == 'g'){
					mint=8;
				}
			}
		}
		if(s.at(0) == 's'){
			if(s.at(1) == 'e'){
				if(s.at(2) == 'p'){
					mint=9;
				}
			}
		}
		if(s.at(0) == 'o'){
			if(s.at(1) == 'c'){
				if(s.at(2) == 't'){
					mint=10;
				}
			}
		}
		if(s.at(0) == 'n'){
			if(s.at(1) == 'o'){
				if(s.at(2) == 'v'){
					mint=11;
				}
			}
		}
		if(s.at(0) == 'd'){
			if(s.at(1) == 'e'){
				if(s.at(2) == 'c'){
					mint=12;
				}
			}
		}
	}

	string inttostr(){
		if(mint == 1){
			return "jan";
		} else if(mint == 2){
			return "feb";
		} else if(mint == 3){
			return "mar";
		} else if(mint == 4){
			return "apr";
		} else if(mint == 5){
			return "may";
		} else if(mint == 6){
			return "jun";
		} else if(mint == 7){
			return "jul";
		} else if(mint == 8){
			return "aug";
		} else if(mint == 9){
			return "sep";
		} else if(mint == 10){
			return "oct";
		} else if(mint == 11){
			return "nov";
		} else if(mint == 12){
			return "dec";
		}
	}

public:
	month(){
		mint=0;
	}

	month(int i){
		mint=i;
	}

	month(string str){
		calc_month(str);
	}

	string getMonthStr(){
		return inttostr();
	}

	int getMonth(){
		return mint;
	}
};

void e2(){
	cout << "enter month as string ";
	string s;
	cin >> s;
	month m(s);

	cout << "Your month is " << m.getMonthStr();
}

int main(){

	e2();

	return 0;
}
/*
 * Output to console:
 *
enter month as string july
Your month is jul
 */
