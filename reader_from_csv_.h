#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class User;
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
	vector<User> readLines();
};