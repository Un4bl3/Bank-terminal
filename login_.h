#pragma once

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
	void ioCreateLogin();
	int isItMatches(vector<User>& user);

};