#pragma once
#include "bankAccount_.h"
#include "userInput_.h"

class BankAccount;

class Transactions {
private:

	double amount_;
	BankAccount& balanceRef;
	
public:

	Transactions(BankAccount& balance);
	void printOptions() const;
	double getBalance();
	void deposit();
	void withdrawal();
	void transferTo(BankAccount& acount, vector<BankAccount>& accounts);
	BankAccount* searchForTransferAcc(int id, vector<BankAccount>& accounts);
	
}; 