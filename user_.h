#pragma once

#include <string>
#include <vector>
using namespace std;

// Declaring that there is a BankAccount class, so that the User class knows that it exists.
// This declaration is necessary to initialize the creation of a bank account inside the User class.
class BankAccount;

class User {
	private:
		int id;
		string name;
		string surname;
		int balance;
		BankAccount *account;
	public:
		User() {};
		User(int id, string name, string surname, int balance);
		User(string name, string surname, int balance);
		void getUser() const;
		string getName() const;
		int getId() const;
		int getBalance() const;
		void disp() const;
		//friend ostream& operator<<(ostream&,const User user);

};