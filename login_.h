#pragma once
/*
* Class for logging in for exsiting users if exist
*/
#include <string>
#include "user_.h"
#include "userInput_.h"
class User;
class Login {
private:
	string typed_name;
	int typed_id;

public:
	Login();
	// Method to get input login and create an object for further verification
	void ioCreateLogin();
	// Metodas kuris verifikuoja ar jau sukurtas User Objektas sutampa su vartuotojo ivesta informacija
	bool isItMatches(vector<User>& user);

};