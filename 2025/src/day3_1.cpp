#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void day3_1() {

  // Declare variables
  int totalJoltage = 0;

  // Read input
  std::string file_path = "../input/day3/input.txt";
  // std::string file_path = "../input/day3/test_input.txt";
  std::ifstream file(file_path);
  std::string bank;

  // Check if input file was found
  if (!file.good()) {
    std::cout << "Input file not found :'(" << std::endl;
  } else {

    // Read battery banks from input file
    while (std::getline(file, bank)) {

      // Compare joltages
      int largestJoltage = 0;
      for (uint8_t i = 0; i < bank.size(); ++i) {
        for (uint8_t j = i + 1; j < bank.size(); ++j) {
          std::string s;
          s += bank[i];
          s += bank[j];
          int joltage = std::stoi(s);
          largestJoltage = std::max(largestJoltage, joltage);
        }
      }
      totalJoltage += largestJoltage;
    }

    // Print result
    std::cout << "Day 3, Part 1 : " << totalJoltage << std::endl;
  }
}
