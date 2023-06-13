#pragma once
class BankAccount;
class User;
class Interface {
public:
	Interface();
	void interfaceLoad();
	void interfaceGuide();
	void interfaceLogin(User a, BankAccount c);
	void InterfaceTransfer();
	void interfaceCreateUser();
	void interfaceTransfer(BankAccount c);
};