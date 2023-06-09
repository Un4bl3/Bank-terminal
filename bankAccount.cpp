
#include <iostream>

#include "bankAccount_.h"
#include "user_.h"

/*	
*	Konstruktorius pagal nutylejima
*/
BankAccount::BankAccount():balance(0) {};


/*	Sukuriama banko saskaita ir siejamas "user" objektas su ja
* 
*	Konstruktorius kuris priema "User" objekto adresa kaip argumenta ir susieja su "BankAccount".
*/
BankAccount::BankAccount(const User &user) : user(&user) {}


/*	Duomenu atvaizdavimas banko saskaitos ir User objekto reiksmes
*	
*	Kreipiamasi i "getUser" funkcija kuri grazina rodykle i "User" objekta
*	-> panaudota tam, kad atvaizduoti rodykle i User objekta nes naudojama draugiska funkcija, kitaip atsiranda klaida. 
*	
*/
void BankAccount::showData() const
{
	cout << "branch is: " << this->branch << endl;
	cout << "Your name is: " << getUser()->getName() << endl;
	cout << "And your id is: " << getUser()->getId() << endl;

}
/*	Gaunamas "User" objektas susietas su "BankAccount" klase 
*	
*	Si funkcija grazina const rodykle i "User" objekta susieta su "BankAccount".
*	Si rodykle leidzia tik perskaityti reiksmes be modifikavimo user duomenu. Taip pat nemodifikuoja "BankAccount" objekta
*	Si funkcija yra perkrauta, nes "user" klaseje yra funkcija su tokiu paciu pavadinimu
*/
const User* BankAccount::getUser() const {
	return user;
}

/*
*	Metodas grazinantis balanso reiksme
* 
*	Reikalinga Transfer klasei, ten reiksme yra apdorojama/nustatoma
*/
double BankAccount::getBalance() const {
	return balance;

}

//BankAccount User::createBankAccc(int user_id, string user_name)
//{
//	return BankAccount(user_id);
//}