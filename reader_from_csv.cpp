#include "reader_from_csv_.h"
#include "user_.h"
// to be continued. 
// To hard task to implement. Lmao.
Reader::Reader(const string& filename) : filename(filename)
{
}

void Reader::openReadFile() {
	if (!file.is_open()) {
		file.open(filename);
	}
}
void Reader::closeReadFile() {
	if (file.is_open()) {
		file.close();
	}
}

vector<User> Reader::readLines() {
	vector<User> users_from_read;
	string line = "";
	while (getline(file, line)) {
		stringstream inputString(line);

		string name;
		string surname;
		int age;
		int id;
		string tempString;
		
		getline(inputString, name, ',');
		getline(inputString, surname, ',');
		getline(inputString, tempString, ',');
		age = atoi(tempString.c_str());
		getline(inputString, tempString, ',');
		id = atoi(tempString.c_str());

		User user(id, name, surname, age);
		users_from_read.push_back(user);
		user.getUser();
		line = "";

	}
	return users_from_read;


}