#include "login_.h"
#include "user_.h"
#include "userInput_.h"
#include "IDgenerator.h"
#include <iostream>

/*	"ObtainingUser" klase yra atsakinga uz "User" klases objekto sukurima 
*   
*/
ObtainingUser::ObtainingUser() {
	IDgenerator generate;
	this->given_id = generate.generateID();
}
ObtainingUser::ObtainingUser(string name, string surname, int age):given_name(name),given_surname(surname),given_age(age)
{
	IDgenerator generate;
	this->given_id = generate.generateID();
}

/*
*	Funkcija skirta iskvietimui is "UserInput" klases "ioInterface" funkcija 
*	kuri praso vartotoja ivesti reikalingus duomenis "user" objektui sukurimui
*/
void ObtainingUser::ioInterface() {
	UserInput::ioInterface(given_name, given_surname, given_age);
	
}
void ObtainingUser::giveID() {
	
}

/*	Sukuriamas "user" objektas is gautu duomenu
* 
*/
User ObtainingUser::createUserObject() const {
	return User(given_id,given_name, given_surname, given_age);
}
