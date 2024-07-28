#include <fstream> 
#include <iostream> 
#include <string>
#include <regex>

using namespace std;

int main() {

	fstream inputFile;
	inputFile.open("../input/input.txt", ios::in);

	// error opening file
	if (!inputFile) {
		cout << "" << endl;
		cout << "Error opening input file" << endl;
		cout << "Execute from within bin directory" << endl;
		cout << "" << endl;
		exit(1);
	}

	vector<string> lines;
	string line;

	// read the file line by line and store each line in the vector
	while (getline(inputFile, line)) {
		cout << line << endl;
		lines.push_back(line);
	}

	inputFile.close();

	////////// grid //////////

	// [-1,-1]  [-1,0]  [-1,1]

	// [0,-1]   [0,0]   [0,1]

	// [1,-1]   [1,0]   [1,1]

	//////////////////////////

	int i = 0;
	int j = 0;
	int prevNumber = 0;
	int sum = 0;

	for (i = 0; i < lines.size(); i++) {
		while (lines[i][j] != '\0') {

			bool withinBorders = (i >= 0) && 
				(i < lines.size()) && 
				(j >= 0) && 
				(j < lines[i].size());

			if (withinBorders && (lines[i][j]) == '*') {

				// upper-left
				if (i - 1 >= 0 && j - 1 >= 0 && isdigit(lines[i-1][j-1])) {
					cout << lines[i][j] << lines[i-1][j-1] << endl;

					int k = j - 1 - 1;
					std::string number (1, lines[i-1][j-1]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i-1][k])) {
						number = lines[i-1][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines[i].size() && isdigit(lines[i-1][k-1])) {
						number = number + lines[i-1][k];
						k++;
					}

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;

				}

				// up
				if (i - 1 >= 0 && isdigit(lines[i-1][j])) {
					cout << lines[i][j] << lines[i-1][j] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// upper-right
				if (i - 1 >= 0 && j + 1 < lines[i].size() && isdigit(lines[i-1][j+1])) {
					cout << lines[i][j] << lines[i-1][j+1] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// left
				if (j - 1 >= 0 && isdigit(lines[i][j-1])) {
					cout << lines[i][j] << lines[i][j-1] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// right
				if (j + 1 < lines[i].size() && isdigit(lines[i][j+1])) {
					cout << lines[i][j] << lines[i][j+1] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// lower-left
				if (i + 1 < lines.size() && j - 1 >= 0 && isdigit(lines[i+1][j-1])) {
					cout << lines[i][j] << lines[i+1][j-1] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// down
				if (i + 1 < lines.size() && isdigit(lines[i+1][j])) {
					cout << lines[i][j] << lines[i+1][j] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

				// lower-right
				if (i + 1 < lines.size() && j + 1 < lines[i].size() && isdigit(lines[i+1][j+1])) {
					cout << lines[i][j] << lines[i+1][j+1] << endl;

					int k = j - 1;
					std::string number (1, lines[i][j]);
					//int number = 0;
					// move backwards
					while (k >= 0 && isdigit(lines[i][k])) {
						number = lines[i][k] + number;
						k--;
					}
					k = j + 1;
					// move forwards
					while (k < lines.size() && isdigit(lines[i][k])) {
						number = number + lines[i][k];
						k++;
					}

					//sum += number;

					if (std::stoi(number) != prevNumber) {
						sum += std::stoi(number);
						prevNumber = std::stoi(number);
					}

					cout << "number: " << number << endl;
				}

			}
			j++;
		}
		j = 0;
		cout << "sum: " << sum << endl;
	}

	return 0;
}
