#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Writer {
private:
	ofstream file;
	string filename;

public:
	Writer();
	Writer(const string& filename);
	bool openFile();
	void closeFile();
	//template<typename T>
	void writeRow( const string& row);
	

};