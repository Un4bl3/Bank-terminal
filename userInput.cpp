#include "userInput_.h"
#include <iostream>
/*
*	Si klase skirta reikalingu kitiems objektams/klasems reiksmiu gavimui ir teksto isspausdinimui
*/

UserInput::UserInput() {};
/*
*	Metodas skirtas User objekto sukurimui
*/
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
/*
*	Metodas skirtas prisijungimui t.y. login klasei
*/

void UserInput::ioCreateLogin(string& name, int& id) {
	cout << endl <<"Type in your name: ";
	cin >> name;
	cout << endl <<"Type in your id: ";
	cin >> id;
}

/*
*	Sie Metodai skirti pinigu perleidimui ir operacijoms su jais.
*/
void UserInput::ioHowMuchToDeposit(double& amount) {
	cout << endl << "How much you want to deposit ";
	cin >> amount;
}
void UserInput::ioHowMuchToWithdrawl(double& amount) {
	cout << endl << "How much you want to withdraw: ";
	cin >> amount;
}
void UserInput::ioHowMuchToTransfer(double& amount) {
	cout << endl << "How much you want to transfer: ";
	cin >> amount;
}