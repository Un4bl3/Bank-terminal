#include "userInput_.h"
#include <iostream>
UserInput::UserInput() {};
void UserInput::ioInterface(string& name, string& surname, int &age)
{
	cout << "Type in name: ";
	cin >> name;
	cout << endl << "Type in surname: ";
	cin >> surname;
	cout << endl << "Type in age: ";
	cin >> age;
}
