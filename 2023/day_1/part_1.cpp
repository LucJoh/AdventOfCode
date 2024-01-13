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
			tot = str.length();
			for(i=0; i<tot; i++)
			{
				if(str[i]>='0' && str[i]<='9')
				{
					num += str[i];
				}
			}
			numbers.push_back(num);
		}
		file.close();
	}

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
		sum += result_int;
	}

	cout << sum-11; //because of blank row in the end of input file

	return 0;
}
