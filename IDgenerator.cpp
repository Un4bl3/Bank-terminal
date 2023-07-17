#include "IDgenerator.h"
#include <string>
#include <chrono>
#include <iostream>

/*
*	Class responsible for generating unique IDs for users.
*/

IDgenerator::IDgenerator() {}

/*
*	Constructor that generates an ID and assigns it to the given parameter.
*	Parameters:
*	- id: Reference to an integer where the generated ID will be assigned.
*/
IDgenerator::IDgenerator(int &id)
{
	id = generateID();

};
/*
*	Method for generating a unique ID based on the current timestamp.
*/
unsigned int IDgenerator::generateID() const{
	auto now = chrono::system_clock::now();
	auto timestamp = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	return static_cast<unsigned int>(timestamp); 
}
