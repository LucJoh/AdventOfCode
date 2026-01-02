#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void day2_1() {

  // Declare variables
  long long sum = 0;

  // Read input
  std::string file_path = "../input/day2/input.txt";
  // std::string file_path = "../input/day2/test_input.txt";
  std::ifstream file(file_path);
  std::string range;

  // Check if input file was found
  if (!file.good()) {
    std::cout << "Input file not found :'(" << std::endl;
  } else {

    // Read ID ranges from input file
    while (std::getline(file, range, ',')) {

      // Remove any new-line characters
      range.erase(std::remove(range.begin(), range.end(), '\n'), range.cend());

      // Filter out strings that contain no digits
      if (std::any_of(range.begin(), range.end(), ::isdigit)) {
        std::stringstream ss(range);
        std::string halves[2];
        std::string quarterPieces[4];

        // Extract max and min ID in range
        uint8_t i = 0;
        while (getline(ss, halves[i], '-')) {
          ++i;
        }

        // Check all IDs within range
        for (long long i = std::stoll(halves[0]); i < std::stoll(halves[1]);
             ++i) {
          std::string id = std::to_string(i);
          std::string halfId1 = id.substr(0, id.length() / 2);
          std::string halfId2 = id.substr(id.length() / 2);
          if (halfId1 == halfId2) {
            sum += i;
          }
        }
      }
    }

    // Print result
    std::cout << "Day 2, Part 1 : " << sum << "\n";
  }
}
