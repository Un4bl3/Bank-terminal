#include "user_.h"
#include "bankAccount_.h"
#include <iostream>

/* 
*	Pagrindinis konstruktorius, kuris sukuria "user" objekta
*/
User::User(int id, string name, string surname, int age):id(id),name(name),surname(surname),age(age) {}

/*
*	Duomenu isgavimas ir spausdinimas
*/
void User::getUser() const
{
	cout << "Your ID is: " << this->id << endl;
	cout << "Your name is: " << this->name << " " << this->surname << endl;
	cout << "And your age: " << this->age << endl;

}
/*
*	Susietiems "user" objektams su "BankAccount" klases objektais funkcijos duomenu gavimui 
*/

string User::getName() const
{
	 return name;
}

int User::getId() const
{
	return id;

}
/*
int User::getAge() const
{
	return age;
	
}
*/