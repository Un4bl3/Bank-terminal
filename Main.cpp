#include <iostream>
#include <string>

#include "atm_.h"
#include "user_.h"
#include "bankAccount_.h"
#include "login_.h"
#include "Main.h"
using namespace std;
	

int main() {
	
	ObtainingUser obtainingUser;
	obtainingUser.ioInterface();
	User a = obtainingUser.createUserObject();
	
	BankAccount c(a);
	//c.showData();
	const User* retrieveUser = c.getUser();
	cout << "User name :" << retrieveUser->getName() << endl;
	cout << "User id: " << retrieveUser->getId() << endl;
	
	
	return 0;
}








