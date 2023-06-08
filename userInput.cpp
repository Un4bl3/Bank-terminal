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
	cout << "Type in your name";
	cin >> name;
	cout << "Type in your id";
	cin >> id;
}
