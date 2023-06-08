#include "reader_from_csv_.h"
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

vector<string> Reader::readLines() {
	vector<string> lines;
	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	return lines;
}