#include "userInput_.h"
#include <iostream>

/*
*	Class for obtaining necessary values and displaying text for other objects/classes
*/


UserInput::UserInput() {};

/*
*	Method for creating a User object
*/
void UserInput::ioCreateUser(string& name, string& surname, int &balance) {
	cout << "Type in name: ";
	cin >> name;
	cout << endl << "Type in surname: ";
	cin >> surname;
	cout << endl << endl;
}

/*
*	Method used for a login class
*/
void UserInput::ioCreateLogin(string& name, int& id) {

	cout << endl <<"Type in your name: ";
	cin >> name;
	cout << endl <<"Type in your id: ";
	cin >> id;
}

/*
*	Method for displaying transaction options
*/
void UserInput::ioTransactionsOptions() {

	cout << endl << "What you want to do?" << endl;
	cout << endl << "1. Deposit";
	cout << endl << "2. Withdraw";
	cout << endl << "3. Transfer";
	cout << endl << "4. Show balance";
	cout << endl << "5. Exit" << endl;

}

/*
*	Method for getting the recipient's ID for a transfer
*/
int UserInput::ioTransferGetID() {

	int id;
	cout << endl << "Enter recipients ID: ";
	cin >> id;
	return id;

}

/*
*	Methods for handling money transfers and operations
*/
void UserInput::ioHowMuchToDeposit(double& amount) {

	cout << endl << "How much you want to deposit ";
	cin >> amount;

}
void UserInput::ioHowMuchToWithdrawal(double& amount) {

	cout << endl << "How much you want to withdraw: ";
	cin >> amount;

}
void UserInput::ioHowMuchToTransfer(double& amount) {

	cout << endl << "How much you want to transfer: ";
	cin >> amount;

}