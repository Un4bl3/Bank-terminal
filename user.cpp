#include "user_.h"
#include "bankAccount_.h"
#include <iostream>
#include <vector>

/* 
*	Pagrindinis konstruktorius, kuris sukuria "user" objekta
*/
User::User(int id, string name, string surname, int age):id(id),name(name),surname(surname),age(age) {}
User::User(string name, string surname, int age) : name(name), surname(surname), age(age) {}

/*
*  Konstruktorius read_from_csv Reader klasei
*/
//User::User(string name, string surnname, int age, int id):name(name),surname(surname),age(age), id(id);
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

int User::getAge() const
{
	return age;
	
}
void User::disp() const
{
	cout << name << " " << id;
}
/*
*	Metodas skirts isgauti vartotojus kurie yra vektoriaus sarase 
*/

// ReturnType is ostream to get back output stream object in this case "cout"
//ostream& operator<<(ostream& os, const User& user) {
//	os << "Name is:" << user.getName();
//	return os;
//}