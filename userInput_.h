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
	// Metodas skirtas duomenu gavimui "Login" klases objektams
	static void ioCreateLogin(string& name, int& id);
	static void ioHowMuchToDeposit(double& amount);
	static void ioHowMuchToWithdrawl(double& amount);
	static void ioHowMuchToTransfer(double& amount);
	static void ioTransactionsOptions();
};