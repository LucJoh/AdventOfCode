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
				str_temp.push_back(str[i]);
				if(str[i]>='0' && str[i]<='9') {
					num += str[i];
				} else if (str_temp.find(digits_text[0]) != std::string::npos) {
					num += digits[0];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[1]) != std::string::npos) {
					num += digits[1];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[2]) != std::string::npos) {
					num += digits[2];
					str_temp = str[i];
				}
				//cout << line;
				//cout << "\n";
			}
			file.close();
		}
		return 0;
	}
