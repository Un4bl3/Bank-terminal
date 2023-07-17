#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "bankAccount_.h"
using namespace std;
class BankAccount;
class Writer {
private:
	ofstream file;
	string filename;

public:
	Writer();
	Writer(const string& filename);
	bool openFile();
	void closeFile();
	void writeFile(const vector<BankAccount> & accounts);

};