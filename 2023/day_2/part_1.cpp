#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	std::vector<std::string> numbers;
	int tot, sum=0, i=0, j=0, k=0;
	string line;
	ifstream file("input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			string num;
			string str = line;
			string str_temp;
			tot = str.length();
			for(i=0; i<tot; i++) {
			}
			cout << line;
			cout << "\n";
		}
		file.close();
	}
	return 0;
}
