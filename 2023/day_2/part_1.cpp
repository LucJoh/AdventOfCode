#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <typeinfo>
using namespace std;

// 12 red cubes, 13 green cubes, and 14 blue cubes

int main() {

	std::vector<std::string> numbers;
	int n;
	int sum = 0;
	int red = 12;
	int green = 13;
	int blue = 14;
	int game_id;
	bool impossible_game = false;
	string line;
	ifstream file("input.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			string num;
			string str = line;
			string word = "";
			string prev_word = "";
			n = str.length();
			for (int i = 0; i < n; i++) {
				if (str[i] == ' ' or str[i] == ';' or str[i] == ',' or str[i] == ':' or i == (n-1)) {
					if (prev_word == "Game") {
						game_id = stoi(word);
					}
					else if (word == "red," or word == "red;" or word == "red" or word == "re") {
						if (stoi(prev_word) > red) {
							impossible_game = true;
							//cout << "not possible red was" << prev_word << endl;
						}
					}
					else if (word == "green," or word == "green;" or word == "green" or word == "gree") {
						if (stoi(prev_word) > green) {
							impossible_game = true;
							//cout << "not possible green was" << prev_word << endl;
						}
					}
					else if (word == "blue," or word == "blue;" or word == "blue" or word == "blu") {
						if (stoi(prev_word) > blue) {
							impossible_game = true;
							//cout << "not possible blue was" << prev_word << endl;
						}
					}
					prev_word = word;
					word = "";
				} 
				else { 
					word += str[i];
				}
			}
			if (impossible_game == false) {
				sum += game_id;
				//cout << "possible, adding " << game_id << endl;
				//cout << "sum is " << sum << endl;
			}
			impossible_game = false;
		}
		file.close();
		cout << sum << endl;
	}
	return 0;
}
