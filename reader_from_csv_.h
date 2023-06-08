#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Reader {
private:
	ifstream file;
	string filename;
public:
	Reader();
	Reader(const string& filename);
	// The reader will be automatically closed closeFile inside
	~Reader() {};
	void openReadFile();
	void closeReadFile();
	vector<string> readLines();
};