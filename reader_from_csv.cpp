#include "reader_from_csv_.h"
#include "user_.h"
/*
*	Class for reading from a file in CSV format
*/

Reader::Reader(const string& filename) : filename(filename) {}

/*
*	This method opens the file if it is closed.
*/
void Reader::openReadFile() {
	if (!file.is_open()) {
		file.open(filename);
	}
}

/*
*	This method closes the file if it is open.
*/
void Reader::closeReadFile() {
	if (file.is_open()) {
		file.close();
	}
}
/*
*	This method reads each value separated by a comma from the file.
*	It returns a vector of User objects to create users based on each vector element later on.
*	The sstream library is used to read from the file.
*
*	First, each value is read and stored in temporary variables.
*	Then, the data from the temporary variables is used to create a User object.
*	These User objects are stored in a dynamic vector.
*/
vector<User> Reader::readLines() {
	vector<User> users_from_read;
	string line = "";
	while (getline(file, line)) {
		stringstream inputString(line);

		string name;
		string surname;
		int balance;
		int id;
		string tempString;
		
		getline(inputString, name, ',');
		getline(inputString, surname, ',');
		getline(inputString, tempString, ',');
		balance = atoi(tempString.c_str());
		getline(inputString, tempString, ',');
		id = atoi(tempString.c_str());

		User user(id, name, surname, balance);
		users_from_read.push_back(user);
		//user.getUser();
		line = "";

	}
	return users_from_read;


}
void Reader::displayUsers(vector<User>& users) {
	for (auto user : users) {
		user.getUser();
	}
} 
