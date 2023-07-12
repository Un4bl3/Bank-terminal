#pragma once
#include<vector>
class BankAccount;
class User;
using namespace std;
class Interface {
public:
	Interface();
	void interfaceLoad();
	void interfaceGuide(vector<User>&users);
	void interfaceLogin(vector<User>&users);
	void InterfaceTransfer();
	void interfaceCreateUser();
	std::vector<User> readUsers();
	void interfaceTransfer(BankAccount c);
};