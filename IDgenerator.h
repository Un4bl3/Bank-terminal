#pragma once
#include <string>

using namespace std;
class IDgenerator {
private: 
	static double ID;
public:
	IDgenerator();
	IDgenerator(int &id);
	unsigned int generateID() const;
};