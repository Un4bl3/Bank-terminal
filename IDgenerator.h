#pragma once
#include <string>

using namespace std;
class IDgenerator {
private: 
	static double ID;
public:
	IDgenerator();
	IDgenerator(int &id);
	// Metodas generuoja skaiciu pagal dabartini laika
	// unsigned kad isvengti bitu "overflow" ir minuso
	unsigned int generateID() const;
};