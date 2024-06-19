#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std;

int main() {

	string line;
	//ifstream input("calibration.txt");

	//std::fstream input("calibration.txt", std::ios_base::in);

	// Check if the file is successfully opened 
	if (!input.is_open()) { 
		cerr << "Error opening the file!" << endl; 
		return 1; 
	}

	while (!input.eof())
	{
		getline(input, line);
		cout << line << endl;
	}

	input.close(); 

	return 0;
}
