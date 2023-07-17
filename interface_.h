#pragma once
#include<vector>
class BankAccount;
class User;
using namespace std;
class Interface {
public:

	Interface();
	void interfaceLoad();
	void interfaceGuide(vector<User>&users, vector<BankAccount>&accounts);
	void interfaceLogin(vector<User>&users,vector<BankAccount>&accounts);
	vector<User> readUsers();
	void interfaceTransfer(BankAccount account, vector<BankAccount>& accounts);
	void interfaceCreateUser(vector<User>& users, vector<BankAccount>& accounts);

};