#include <fstream>
#include <iostream>
#include <string>

void day1_1() {
  // Declare variables
  int sum = 0;
  int rotate = 0;
  int dialIndex = 50;
  bool clockwise;
  // Read input
  std::string file_path = "../input/day1/input.txt";
  std::ifstream file(file_path);
  std::string line;
  // Check if input file was found
  if (!file.good()) {
    std::cout << "Input file not found :'(" << std::endl;
  } else {
    // Read input file line by line
    while (std::getline(file, line)) {
      // Determine which way to turn dial
      if (line[0] == 'R') {
        clockwise = true;
      } else {
        clockwise = false;
      }
      // Remove the "R" or "L" from the line
      line.erase(0, 1);
      // Determine how many steps to ritate dial
      rotate = std::stoi(line);
      if (clockwise) {
        dialIndex = dialIndex + rotate;
      } else {
        dialIndex = dialIndex - rotate;
      }
      // Keep dial within limit (0-99)
      dialIndex = (dialIndex + 100) % 100;
      if (dialIndex == 0) {
        sum += 1;
      }
    }
    // Print result
    std::cout << "Day 1, Part 1 : " << sum << "\n";
  }
}
