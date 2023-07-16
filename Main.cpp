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
#include "interface_.h"
#include "Main.h"
#include <Windows.h>
//using namespace std;
vector<BankAccount> connectingLists(vector<User>& users) {
	vector<BankAccount>accounts;
	for (auto user : users) {
		BankAccount account(user);
		account.disp();
		accounts.push_back(account);

	}
	return accounts;
}

int main() {
	Interface guide;
	vector<User>list = guide.readUsers();
	//list[2].disp();
	
	vector<BankAccount>accounts = connectingLists(list);
	accounts[1].disp(); 
	guide.interfaceLoad();
	guide.interfaceGuide(list,accounts);
		

	return 0;
}

// Everthing out of main

	// Konsoles lango dydzio nustatymas
	//HWND console = GetConsoleWindow();
	//RECT r;
	//GetWindowRect(console, &r);
	//MoveWindow(console, r.left, r.top, 800, 600, TRUE);


	//Interface guide;
	//guide.interfaceLoad();
	//guide.interfaceGuide();
	/*ObtainingUser obtainingUser;
	obtainingUser.ioCreateUser();
	User a = obtainingUser.createUserObject();
	obtainingUser.ioCreateUser();
	User b = obtainingUser.createUserObject();
	BankAccount c(a);
	BankAccount recipient(b);
	////c.showData();
	const User* retrieveUser = c.getUser();
	cout << "User name :" << retrieveUser->getName() << endl;
	cout << "User id: " << retrieveUser->getId() << endl;
	*/
	// Bank Account and transactions
		/*Transactions show(c);
		show.deposit();
		show.withdrawl();
		show.transfer(recipient);
		cout << show.getBalance();

		Transactions recipeint_show(recipient);
		cout << recipeint_show.getBalance();*/

		/*
			* Comeback later to include writing of seperate type vars
			* idea: vector <Ts...>
			Writer writer("data.csv");

			if (writer.openFile()) {
				writer.writeRow({  retrieveUser->getName(),retrieveUser->getName() });

				cout << "all good";
				writer.closeFile();
			}
			else {
				cout << "failed to open!";
			}
			*/




