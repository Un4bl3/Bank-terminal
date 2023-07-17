#include <iostream>
#include "bankAccount_.h"
#include "user_.h"

BankAccount::BankAccount() {};

/*
*	Constructor that creates a BankAccount object based on the given User object.
*/
BankAccount::BankAccount(const User &user) : user(&user) {

	this->name = user.getName();
	this->id = user.getId();
	this->balance = user.getBalance();

}

/*
*	Displays the bank account's data, including the associated user's information.
*	The getUser() function is called to retrieve the User object's pointer.
*/
void BankAccount::showData() const {

	cout << "branch is: " << this->branch << endl;
	cout << "Your name is: " << getUser()->getName() << endl;
	cout << "And your id is: " << getUser()->getId() << endl;

}
/*
*	Returns the ID of the bank account.
*/
int BankAccount::getID() {
	return id;
}
/*
*	Returns the name of the bank account owner.
*/
string BankAccount::getName() {
	return name;
}

/*
*	Displays the bank account's data: name, ID, and balance.
*/
void BankAccount::disp() const {
	cout << name << " " << id << " " << balance << endl;
}

/*
*	Returns a pointer to the associated User object.
*/
const User* BankAccount::getUser() const {
	return user;
}

/*
*	Returns the balance of the bank account.
*/
double BankAccount::getBalance()  {
	return balance;
}

/*
*	Updates the balance of the bank account by adding the given amount.
*	Parameters:
*	- amount: The amount to be added to the balance.
*/
void BankAccount::updateBalanceAmount(double amount) {
	balance += amount;
}

//vector<BankAccount> BankAccount::createBankAccountsFromList(vector<User>&users)
//{
//	for (auto user : users) {
//
//	}
//	return vector<BankAccount>();
//}
