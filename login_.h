#pragma once
#include <string>
using namespace std;
class User;
class ObtainingUser {
private:
	int given_id;
	string given_name;
	string given_surname;
	int given_age;
	
public: 
	void ioInterface();
	ObtainingUser();
	ObtainingUser(string name, string surname, int age);
	void giveID();
	User createUserObject() const;
};
