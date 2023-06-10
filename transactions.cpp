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
Transactions::Transactions(BankAccount& balance) : balanceRef(balance), amount_(0) {}

double Transactions::getBalance() {
	return balanceRef.getBalance();
}
void Transactions::deposit() {
	//currentAmount += amount;
	UserInput::ioHowMuchToDeposit(amount_);
	balanceRef.updateBalanceAmount(amount_);
}
void Transactions::withdrawl() {
	UserInput::ioHowMuchToWithdrawl(amount_);
	balanceRef.updateBalanceAmount(-amount_);
}
void Transactions::transfer(BankAccount& recipeint) {
	UserInput::ioHowMuchToTransfer(amount_);
	if (amount_ > balanceRef.getBalance()) {
		cout << "Insufficient balance. Transfer cannot be done." << endl ;
		return;
	}
	balanceRef.updateBalanceAmount(-amount_);
	recipeint.updateBalanceAmount(amount_);
	cout << "transfer completed";
};
//void Transactions::setAmount() {
	
	//deposit();
//}