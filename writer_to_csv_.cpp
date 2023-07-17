#include "writer_to_csv_.h"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

Writer::Writer(const string& filename):filename(filename)
{
}
bool Writer::openFile() {
	file.open(filename);
	return file.is_open();
}
void Writer::closeFile() {
	if (file.is_open()) {
		file.close();
	}
}
// Come back later when understanding will improve
// Need to write string and int provided some vectors
// Also there is problem in output. Occurance of numbers between spaces.
//template<typename Ts...>
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
//void Writer::writeObj((char*)&obj, sizeof(obj));

