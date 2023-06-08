#pragma once
#include <string>
using namespace std;
/*
*  Si klase skirta duomenu gavimui is vartotojo
*/
class UserInput {
public:
	UserInput();
	// Funkicija skirta duomenu gavimui "obtainingUser" klases objektams
	static void ioCreateUser(string& name, string& surname, int& age);
	static void ioLogin(string& name, string& id);
};