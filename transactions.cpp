#include "bankAccount_.h"
#include "transactions_.h"
#include <iostream>
/*
Transactions::Transactions() {};
Transactions::Transactions(BankAccount& balance) : balanceRef(balance) {}
//Transactions::Transactions(const BankAccount &balance):balanceRef(balance){}

*/
//Transactions::Transactions() {}
// Direct reference to balance object
Transactions::Transactions(BankAccount& balance) : balanceRef(balance) {
	this->currentAmount = balanceRef.getBalance();
}
//Transactions::Transactions(const BankAccount& balance) : balanceRef(balance) {}
void Transactions::getBalance() {
	 
	cout << currentAmount;
}
void Transactions::deposit(double amount) {
	//currentAmount += amount;
	balanceRef.updateBalanceAmount(amount);
}
