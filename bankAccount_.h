#pragma once

#include "user_.h"
#include <vector>
#include <string>
using namespace std;

class User;

class BankAccount : protected User {
private: 
	string branch = "OOO";
	int id;
	string name;
	double balance;
	const User *user;
public:
	BankAccount() ;
	
	BankAccount(const User& user);
	void createBankAccount(const vector<User>& users);
	void showData() const;
	const User* getUser() const;
	double getBalance() ;
	void updateBalanceAmount(double amount);
	vector<BankAccount> createBankAccountsFromList(vector<User>&users);
	void disp() const;
	int getID();
};