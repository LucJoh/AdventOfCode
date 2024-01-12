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
			for(i=0; i<tot; i++)
			{
				str_temp.push_back(str);
				if(str[i]>='0' && str[i]<='9')
				{
					num += str[i];
				}
			}
			numbers.push_back(num);
		}
		file.close();
	}

	return 0;
}
