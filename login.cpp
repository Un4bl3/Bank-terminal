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
int Login::isItMatches(vector<User>& users) {
	int n=0;
	for (auto user : users) {
		n++;
		if (user.getName() == typed_name && user.getId() == typed_id) {
			
			cout << endl << "Access granted";
			return n;
		}
	}
	cout << endl << "You must leave";
	return -1;
}
