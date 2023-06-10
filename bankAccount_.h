#pragma once

#include "user_.h"
#include <string>
using namespace std;

class User;

class BankAccount {
private: 
	string branch = "OOO";
	int id;
	string name="";
	double balance = 0;
	const User *user;
public:
	BankAccount() ;
	
	BankAccount(const User& user);

	void showData() const;
	const User* getUser() const;
	double getBalance() ;
	void updateBalanceAmount(double amount);
};