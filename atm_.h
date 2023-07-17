#pragma once
#include <string>
using namespace std;



class ATM {
public:
	int id;
	int moneyInside;
	string location;
	bool statusActive;
public:
	ATM(int id, int money, string whereItPlaced, bool isItActive);
	void getAtm() const;

};

