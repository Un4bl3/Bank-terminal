#pragma once
#include "bankAccount_.h"
#include "userInput_.h"
/*
*	Si klase yra atsakinga uz pinigu keliavima
*/
class BankAccount;
class Transactions {
private:
	double amount_;
	BankAccount& balanceRef;
	
public:
	//Transactions();
	Transactions(BankAccount& balance);
	void printOptions() const;
	double getBalance();
	void deposit();
	void withdrawl();
	void transferTo(BankAccount& acount, vector<BankAccount>& accounts);
	BankAccount* searchForTransferAcc(int id, vector<BankAccount>& accounts);
	
}; 