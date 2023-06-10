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
	//Transactions(const BankAccount& balance);
	Transactions(BankAccount& balance);
	double getBalance();
	void deposit();
	void withdrawl();
	void setAmount();
	void transfer();
}; 