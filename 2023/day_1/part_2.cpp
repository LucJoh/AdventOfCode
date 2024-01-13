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

	std::vector<std::string> digits_text{"zero","one",
		"two","three","four","five","six","seven","eight","nine"};

	std::vector<std::string> digits{"0","1","2","3","4","5",
		"6","7","8","9"};

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
				} else if (str_temp.find(digits_text[3]) != std::string::npos) {
					num += digits[3];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[4]) != std::string::npos) {
					num += digits[4];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[5]) != std::string::npos) {
					num += digits[5];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[6]) != std::string::npos) {
					num += digits[6];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[7]) != std::string::npos) {
					num += digits[7];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[8]) != std::string::npos) {
					num += digits[8];
					str_temp = str[i];
				} else if (str_temp.find(digits_text[9]) != std::string::npos) {
					num += digits[9];
					str_temp = str[i];
				}
			}
			numbers.push_back(num);
		}
		file.close();
	}

	/*for (const auto& number : numbers) {
		cout << number << endl;
		}*/

	std::vector<int> ints;
	std::transform(numbers.begin(), numbers.end(), std::back_inserter(ints),
			[&](std::string s) {
			std::stringstream ss(s);
			int i;
			ss >> i;
			return i;
			});

	for(int x=0; x<ints.size(); x++)
	{
		int n = ints[x]; 
		string s = to_string(n); 
		int first_digit = s.front() - '0'; 
		int last_digit = s.back() - '0';
		string s1 = to_string(first_digit);
		string s2 = to_string(last_digit);
		string result_string = s1+s2;
		int result_int = stoi(result_string);
		sum = sum + result_int;
		/*cout << result_int;
		cout << "\n";
		cout << sum;
		cout << "\n";*/
	}

	cout << sum-81; //because of blank row in the end of input file
	cout << "\n";

	return 0;
}
