#include "bankAccount_.h"
#include "transactions_.h"
#include <iostream>
/*
Transactions::Transactions() {};
Transactions::Transactions(BankAccount& balance) : balanceRef(balance) {}
//Transactions::Transactions(const BankAccount &balance):balanceRef(balance){}

*/

/*	Tiesioginis BankAccount objekto gavimas
*	Sis konstruktorius isgauna objekta ir priskiria ji prie balanceRef, tam kad veliau
*	butu galima modifikuoti reiksme tiesiogiai is sios klases vidaus.
*/ 

Transactions::Transactions(BankAccount& balance) : balanceRef(balance), amount_(0){}


void Transactions::printOptions() const {
	UserInput::ioTransactionsOptions();
}
/*
*	Grazinamas BankAccount objekto balansas
*/
double Transactions::getBalance() {
	return balanceRef.getBalance();
}
/*
*	Metodas pinigu idejimui. Padidina BankAccount objekto balanso reiksme
*/
void Transactions::deposit() {
	//currentAmount += amount;
	UserInput::ioHowMuchToDeposit(amount_);
	balanceRef.updateBalanceAmount(amount_);
}
/*
*	Pinigu isdavimui. Pamazina BankAccount objekto balanso reiksme
*/
void Transactions::withdrawl() {
	UserInput::ioHowMuchToWithdrawl(amount_);
	if (amount_ > balanceRef.getBalance()) {
		cout << "Insufficient balance. Withdrawl cannot be done." << endl;
		return;
	}
	cout << "transfer completed";
	balanceRef.updateBalanceAmount(-amount_);
}
BankAccount* Transactions::searchForTransferAcc(int id, vector<BankAccount>& accounts)
{
	for (auto &account : accounts) {
		if (id == account.getID()) {
			return &account;
		}
	}
	return nullptr;
}

void Transactions::transferTo(BankAccount& account, vector<BankAccount>& accounts) {
	
	int id;
	id = UserInput::ioTransferGetID();
	
	BankAccount* recipientPtr = Transactions::searchForTransferAcc(id, accounts);
	UserInput::ioHowMuchToTransfer(amount_);
	if (amount_ > account.getBalance()) {
		cout << "Insufficient balance. Transfer cannot be done." << endl ;
		return;
	}
	account.updateBalanceAmount(-amount_);
	recipientPtr->updateBalanceAmount(amount_);
	recipientPtr->disp();
	
	cout << "transfer completed";
};
//void Transactions::setAmount() {
	
	//deposit();
//}