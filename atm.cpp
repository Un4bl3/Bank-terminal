#include "atm_.h"
#include <iostream>


ATM::ATM(int id, int money, string whereItPlaced, bool isItActive) :id(id), moneyInside(money), location(whereItPlaced), statusActive(isItActive) {

}


void ATM::getAtm() const
{
	cout << "The ID is: " << this->id << endl;
	cout << "There is " << this->moneyInside << "$ inside" << endl;
	cout << "ATM placed in " << this->location << "city" << endl;
	cout << "The ATM is " << ((statusActive == true) ? "active" : "inactive") << endl;

}