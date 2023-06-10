#include "userInput_.h"
#include <iostream>
UserInput::UserInput() {};
void UserInput::ioCreateUser(string& name, string& surname, int &age)
{
	cout << "Type in name: ";
	cin >> name;
	cout << endl << "Type in surname: ";
	cin >> surname;
	cout << endl << "Type in age: ";
	cin >> age;
	cout << endl << endl;
}
void UserInput::ioCreateLogin(string& name, int& id) {
	cout << endl <<"Type in your name: ";
	cin >> name;
	cout << endl <<"Type in your id: ";
	cin >> id;
}
void UserInput::ioHowMuchToDeposit(double& amount) {
	cout << endl << "How much you want to deposit ";
	cin >> amount;
}
void UserInput::ioHowMuchToWithdrawl(double& amount) {
	cout << endl << "How much you want to withdrawl: ";
	cin >> amount;
}
void UserInput::ioHowMuchToTransfer(double& amount) {
	cout << endl << "How much you want to transfer: ";
	cin >> amount;
}