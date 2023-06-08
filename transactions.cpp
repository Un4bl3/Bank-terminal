#include "bankAccount_.h"
#include "transactions_.h"
#include <iostream>


Transactions::Transactions():balance(BankAccount())

// Direct reference to balance object
Transactions::Transactions(BankAccount& balance) : balance(balance) {}
void Transactions::getBalanceFromBa() {
	currentAmount = balance.getBalance();
	cout << currentAmount;
}
