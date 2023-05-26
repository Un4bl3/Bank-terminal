#include "login_.h"
#include "user_.h"
#include "userInput_.h"
#include <iostream>

/*	"ObtainingUser" klase yra atsakinga uz "User" klases objekto sukurima 
*   
*/
ObtainingUser::ObtainingUser() {}
ObtainingUser::ObtainingUser(string name, string surname, int age):given_name(name),given_surname(surname),given_age(age){}

/*
*	Funkcija skirta iskvietimui is "UserInput" klases "ioInterface" funkcija 
*	kuri praso vartotoja ivesti reikalingus duomenis "user" objektui sukurimui
*/
void ObtainingUser::ioInterface() {
	UserInput::ioInterface(given_name, given_surname, given_age);
	
}

/*	Sukuriamas "user" objektas is gautu duomenu
* 
*/
User ObtainingUser::createUserObject() const {
	return User(given_name, given_surname, given_age);
}
