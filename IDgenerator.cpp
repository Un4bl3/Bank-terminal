#include "IDgenerator.h"
#include <string>
#include <chrono>
#include <iostream>
IDgenerator::IDgenerator() {}
IDgenerator::IDgenerator(int &id)
{
	id = generateID();

};
int IDgenerator::generateID() const{
	auto now = chrono::system_clock::now();
	auto timestamp = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();
	return static_cast<int>(timestamp);
}
