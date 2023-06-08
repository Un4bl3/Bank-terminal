#include <iostream>
#include <string>
#include <vector>
#include "atm_.h"
#include "user_.h"
#include "bankAccount_.h"
#include "obtainUser_.h"
#include "writer_to_csv_.h"
#include "reader_from_csv_.h"
#include "login_.h"
#include "Main.h"

using namespace std;
	

int main() {
	
	ObtainingUser obtainingUser;
	obtainingUser.ioCreateUser();
	User a = obtainingUser.createUserObject();
	
	BankAccount c(a);
	//c.showData();
	const User* retrieveUser = c.getUser();
	cout << "User name :" << retrieveUser->getName() << endl;
	cout << "User id: " << retrieveUser->getId() << endl;



	

	// use ioLogin in member functions
	
	// Create login obj
	Login login;
	login.ioCreateLogin();
	// pass info to Login from User 
	login.isItMatches(a);
	// Verify whether it matches












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
	

	return 0;
}








