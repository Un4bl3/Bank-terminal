#pragma once
#include <string>
using namespace std;

struct UserInput {
public:

	UserInput();
	static void ioCreateUser(string& name, string& surname, int& age);
	static void ioCreateLogin(string& name, int& id);
	static void ioHowMuchToDeposit(double& amount);
	static void ioHowMuchToWithdrawal(double& amount);
	static void ioHowMuchToTransfer(double& amount);
	static void ioTransactionsOptions();
	static int ioTransferGetID();

};