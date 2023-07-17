#pragma once
#include <string>
using namespace std;
class User;
class ObtainingUser {
private:
	int given_id;
	string given_name;
	string given_surname;
	int given_balance;
	
public: 
	void ioCreateUser();
	ObtainingUser();
	ObtainingUser(string name, string surname, int balance);
	User createUserObject() const;
	string getName() const;
};
