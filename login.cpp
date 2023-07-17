#include <iostream>
#include "login_.h"
#include "userInput_.h"

/*
*	Class responsible for handling user login functionality.
*/
Login::Login() {}

/*
*	Method for obtaining login information from the user.
*	Calls the ioCreateLogin function from the UserInput class to prompt for the name and ID.
*/
void Login::ioCreateLogin()
{
	UserInput::ioCreateLogin(typed_name, typed_id);
}

/*
*	Method for checking if the provided login information matches any user in the vector of users.
*	Iterates through the users vector and compares the name and ID.
*	If a match is found, grants access and returns the index position of the matched user in the vector.
*	If no match is found, denies access and returns -1.
*
*	Parameters:
*	- users: The vector of User objects to compare the login information against.
*
*	Returns:
*	- The index position of the matched user in the vector if a match is found, or -1 if no match is found.
*/
int Login::isItMatches(vector<User>& users) {
	int n=0;
	for (auto user : users) {
		n++;
		if (user.getName() == typed_name && user.getId() == typed_id) {
			
			cout << endl << "Access granted. ";
			return n;
		}
	}
	cout << endl << "Access denied. ";
	return -1;
}
