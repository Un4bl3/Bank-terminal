#include "reader_from_csv_.h"
#include "user_.h"
// to be continued. 
// the task is too hard to implement now.
Reader::Reader(const string& filename) : filename(filename)
{
}
/*
*  Sis metodas atidaro faila, jeigu jis yra uzdarytas 
*/
void Reader::openReadFile() {
	if (!file.is_open()) {
		file.open(filename);
	}
}
/*
*  Sis metodas uzdaro faila, jeigu jis yra atidarytas 
*/
void Reader::closeReadFile() {
	if (file.is_open()) {
		file.close();
	}
}
/*
*	Sis metodas nuskaito kiekviena reiksme po kablelio. Grazinamas objekto User vektorius,
*	tam kad veliau galima butu sukurti user pagal kiekviena vektoraius elementa.
*	Papildonai naudojama biblioteka sstream, kad nuskaityti is failo.
*	
*	Pirma nuskaitoma reiksme ir sudedama i laikina kintamaji. Veliau is tu kintamuju duomenys keliauja i objekta User sukurti objekta.
*	Sie objektai irasomi i dinamini vektoriu. 
*	
*/
vector<User> Reader::readLines() {
	vector<User> users_from_read;
	string line = "";
	while (getline(file, line)) {
		stringstream inputString(line);

		string name;
		string surname;
		int balance;
		int id;
		string tempString;
		
		getline(inputString, name, ',');
		getline(inputString, surname, ',');
		getline(inputString, tempString, ',');
		balance = atoi(tempString.c_str());
		getline(inputString, tempString, ',');
		id = atoi(tempString.c_str());

		User user(id, name, surname, balance);
		users_from_read.push_back(user);
		//user.getUser();
		line = "";

	}
	return users_from_read;


}
void Reader::displayUsers(vector<User>& users) {
	for (auto user : users) {
		user.getUser();
	}
} 
