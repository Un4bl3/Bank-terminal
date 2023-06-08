#include <iostream>
#include "login_.h"
#include "userInput_.h"
Login::Login() {}
void Login::ioCreateLogin()
{
	UserInput::ioCreateLogin(typed_name, typed_id);
}
void Login::isItMatches(User User) {
	if (User.getName() == typed_name) {
		cout << "Name is good";
	}
}
