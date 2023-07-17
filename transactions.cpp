#include "bankAccount_.h"
#include "transactions_.h"
#include <iostream>


/*
*	Direct BankAccount object retrieval
*	This constructor retrieves the object and assigns it to balanceRef so that
*	the value can be modified directly from within this class.
*/
Transactions::Transactions(BankAccount& balance) : balanceRef(balance), amount_(0) {}


void Transactions::printOptions() const {

	UserInput::ioTransactionsOptions();

}

/*
*	Returns the balance of the BankAccount object
*/
double Transactions::getBalance() {

	return balanceRef.getBalance();

}
/*
*	Method for depositing money. Increases the balance of the BankAccount object
*/
void Transactions::deposit() {

	UserInput::ioHowMuchToDeposit(amount_);
	balanceRef.updateBalanceAmount(amount_);

}

/*
*	Method for withdrawing money. Decreases the balance of the BankAccount object
*/
void Transactions::withdrawal() {

	UserInput::ioHowMuchToWithdrawal(amount_);

	if (amount_ > balanceRef.getBalance()) {
		cout << "Insufficient balance. Withdrawl cannot be done." << endl;
		return;
	}

	cout << "transfer completed";
	balanceRef.updateBalanceAmount(-amount_);

}
/*
*	Method responsible for searching the recipient bankaccount by ID.
*	Iterates through the vector of BankAccount objects and checks if the ID matches.
*	If a match is found, a pointer to the BankAccount object is returned.
*	If no match is found, a nullptr is returned
*/
BankAccount* Transactions::searchForTransferAcc(int id, vector<BankAccount>& accounts)
{

	for (auto &account : accounts) {
		if (id == account.getID()) {
			return &account;
		}
	}
	return nullptr;

}
/*
*	Method responsible for transferring funds to the desired account.
*	It utilizes another member method to find the recipient's account.
*	UserInput class methods are used to prompt for the recipient's ID and the amount to transfer.
*	The recipient's account is obtained in the form of a pointer.
*	The transfer amount is validated against the current account's balance, and if it exceeds, the transfer is aborted.
*	The balances of both the current account and the recipient account are updated accordingly by subtracting and adding the transfer amount, respectively.
*	The recipient's information is displayed using the disp() method of the BankAccount object through the pointer.
*/
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