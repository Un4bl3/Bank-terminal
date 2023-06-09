#pragma once
#include "bankAccount_.h"
/*
*	Si klase yra atsakinga uz pinigu keliavima
*/
class BankAccount;
class Transactions {
private:
	double currentAmount;
	double change;
	const BankAccount& balanceRef;
public:
	//Transactions();
	Transactions(const BankAccount& balance);
	Transactions(BankAccount& balance);
	void getBalanceFromBa();
	void deposit();
	void transfer();
	void withdrawl();
};