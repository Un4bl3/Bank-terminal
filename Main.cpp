#include <iostream>
#include <string>
#include <vector>
#include "atm_.h"
#include "user_.h"
#include "bankAccount_.h"
#include "obtainUser_.h"
#include "writer_to_csv_.h"
#include "reader_from_csv_.h"
#include "transactions_.h"
#include "login_.h"
#include "interface_.h"#include <Windows.h>
using namespace std;
vector<BankAccount> connectingLists(vector<User>& users) {
	vector<BankAccount>accounts;
	for (auto user : users) {
		BankAccount account(user);
		accounts.push_back(account);

	}
	return accounts;
}

int main() {
	Interface guide;
	vector<User>list = guide.readUsers();
	
	vector<BankAccount>accounts = connectingLists(list); 
	guide.interfaceLoad();
	guide.interfaceGuide(list,accounts);
		

	return 0;
}
