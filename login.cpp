/*
*	Klase skirta vartotojo prisijungimui
*/

#include <iostream>
#include "login_.h"
#include "userInput_.h"

/*
*	Konstruktorius pagal nutylejima.
*/
Login::Login() {}

/*
*	Sis metodas yra skirtas tam, kad sukurti teksto lauka kuris paprasytu vartotoja duomenu.
*/
void Login::ioCreateLogin()
{
	UserInput::ioCreateLogin(typed_name, typed_id);
}

/*
*	Tikrinama ar irasytas tekstas atitinka egzistuojanciam User objektui
*/
bool Login::isItMatches(vector<User>& users) {
	for (auto user : users) {
		if (user.getName() == typed_name && user.getId() == typed_id) {
			user.getUser();
			cout << endl << "Access granted";
			return true;
		}
	}
	cout << endl << "You must leave";
	return false;
}
