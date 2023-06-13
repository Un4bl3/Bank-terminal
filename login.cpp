#include <iostream>
#include "login_.h"
#include "userInput_.h"
Login::Login() {}
void Login::ioCreateLogin()
{
	UserInput::ioCreateLogin(typed_name, typed_id);
}
bool Login::isItMatches(User User) {
	if (User.getName() == typed_name && User.getId() == typed_id) {
		cout << endl << "Access granted";
		return true;
	}
	else {
		cout << endl << "You must leave";
		return false;
	}
}
