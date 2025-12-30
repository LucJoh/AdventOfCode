#include <fstream>
#include <iostream>
#include <string>

void day1_2() {
  // Declare variables
  int sum = 0;
  int rotate = 0;
  int dialIndex = 50;
  int dialIndexPrev = 50;
  bool clockwise = false;

  // Read input
  // std::string file_path = "../input/day1/test_input.txt";
  std::string file_path = "../input/day1/input.txt";
  std::ifstream file(file_path);
  std::string line;

  // Check if input file was found
  if (!file.good()) {
    std::cout << "Input file not found ˙◠˙" << std::endl;
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

      // Determine how many steps to rotate dial
      rotate = std::stoi(line);
      dialIndexPrev = dialIndex;
      if (clockwise) {
        dialIndex += rotate;
      } else {
        dialIndex -= rotate;
      }

      int crossedZero = 0;

      // Count full rotations
      crossedZero += rotate / 100;

      // Calculate reminder after full rotations
      int reminder = rotate % 100;

      // Check if partial rotation crossed zero
      if (clockwise) {
        if (dialIndexPrev + reminder >= 100) {
          ++crossedZero;
        }
      } else {
        if (dialIndexPrev != 0 && reminder >= dialIndexPrev) {
          ++crossedZero;
        }
      }

      // Keep dial within limit (0-99)
      dialIndex = (dialIndex % 100 + 100) % 100;

      // Calculate result
      sum += crossedZero;
    }

    // Print result
    std::cout << "Day 1, Part 2 : " << sum << "\n";
  }
}
