#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "writer_to_csv_.h"
/*
*	Class responsible for writing bank accounts into a file in CSV format
*/

Writer::Writer(const string& filename):filename(filename) {}

// Open the file for writing
bool Writer::openFile() {

	file.open(filename);
	return file.is_open();

}

// Close the file if it's open
void Writer::closeFile() {

	if (file.is_open()) {
		file.close();
	}

}

// Write data from vector<BankAccount> to the file in CSV format
void Writer::writeFile(const vector<BankAccount> &accounts) {

	openFile();
	if (!file.is_open()) {
		cout << "Error: file is closed" << endl;
		return;
	}
	else {
		for (auto account : accounts) {
			file << "\"" << account.getName() << "\",\""  << "---" << "\"," << account.getBalance() << "," << account.getID() << endl;
		}
	}
	closeFile();

}

