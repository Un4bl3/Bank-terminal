#pragma once

#include <string>
using namespace std;
/*
*	Deklarajuoma "BankAccount" klase tam, kad "user" klases turetu supratima, kad egzistuoja tokia klase. Nes viduje yra naudojama draugiska funkcija
*/
// declaraing that there is BankAccount class, so that User class knows that it exists. 
//	to initialize creation of b. account inside User class.
class BankAccount;
// Creates objects for users containing their personal information, their created bankaccount and card
class User {
	private:
		int id;
		string name;
		string surname;
		int age;
		BankAccount *account;
	public:
		User() {};
		User(int id, string name, string surname, int age);
		User(string name, string surname, int age);
		
		// returns information of user3
		void getUser() const;
		// boiler plate
		string getName() const;
		int getId() const;
		//int getAge();



		//BankAccount createBankAccc(int id, string name);
		//void createCard(int id, string name);

};