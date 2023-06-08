#include "IDgenerator.h"
#include <string>
#include <chrono>
#include <iostream>
IDgenerator::IDgenerator() {}
IDgenerator::IDgenerator(int &id)
{
	id = generateID();

};
// Think of a better algorythm
unsigned int IDgenerator::generateID() const{
	auto now = chrono::system_clock::now();
	auto timestamp = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	return static_cast<unsigned int>(timestamp); 
}
