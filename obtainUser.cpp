#include "obtainUser_.h"
#include "user_.h"
#include "userInput_.h"
#include "IDgenerator.h"
#include <iostream>

/*
*	Class responsible for obtaining user information and creating User objects.
*/


/*
*	Default constructor that generates a unique ID using the IDgenerator object.
*/
ObtainingUser::ObtainingUser() {
	IDgenerator generate;
	this->given_id = generate.generateID();
}

/*
*	Parameterized constructor that generates a unique ID using the IDgenerator object and initializes the given_name, given_surname, and given_balance members.
*/
ObtainingUser::ObtainingUser(string name, string surname, int balance):given_name(name),given_surname(surname),given_balance(balance)
{
	IDgenerator generate;
	this->given_id = generate.generateID();
}

/*
*	Method for obtaining user information by calling the ioCreateUser function from the UserInput class.
*/
void ObtainingUser::ioCreateUser() {
	UserInput::ioCreateUser(given_name, given_surname, given_balance);
	
}

/*	
*	Method for creating a User object using the obtained user information.
*/
User ObtainingUser::createUserObject() const {
	return User(given_id,given_name, given_surname, 0);
}
/*
*	Method for retrieving the name of the user.
*/
string ObtainingUser::getName() const {
	return given_name;
}
