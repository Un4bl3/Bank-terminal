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
//template<typename T>
void Writer::writeRow(const string &  row) {
	if (!file.is_open()) {
		cout << "Error: file is closed" << endl;
		return;
	}
	else {
		for (size_t i = 0; i < row.size(); i++) {
			file << row[i];
			if (i < row.size() - 1) {
				file << ', ';
			}
		}
		file << endl;
	}
}

