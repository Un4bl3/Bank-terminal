#include "user_.h"
#include "bankAccount_.h"
#include <iostream>
#include <vector>

// User constructor with ID, name, surname, and balance parameters
User::User(int id, string name, string surname, int balance):id(id),name(name),surname(surname),balance(balance) {}

// User constructor with name, surname, and balance parameters (ID will be assigned later)
User::User(string name, string surname, int balance) : name(name), surname(surname), balance(balance) {}

// Print user information: ID, name, surname, and balance
void User::getUser() const {
	cout << "The ID is: " << this->id << endl;
	cout << "The name and surname is: " << this->name << " " << this->surname << endl;
	cout << "The balance: " << this->balance << endl;

}

// Get the user's name
string User::getName() const
{
	 return name;
}

// Get the user's ID
int User::getId() const
{
	return id;
}

// Get the user's balance
int User::getBalance() const
{
	return balance;
}

// Display the user's name and ID
void User::disp() const {
	cout << name << " " << id << " ";
}


//
//ostream& operator<<(ostream& os, const User& user) {
//	os << "Name is:" << user.getName();
//	return os;
//}