#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>

void day1_1();
void day1_2();
void day2_1();
void day2_2();
void day3_1();
void day3_2();

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: run_day <day> <part>\n";
    return 1;
  }

  int day = std::stoi(argv[1]);
  int part = std::stoi(argv[2]);

  std::map<std::pair<int, int>, std::function<void()>> functions = {
      {{1, 1}, day1_1}, {{1, 2}, day1_2}, {{2, 1}, day2_1},
      {{2, 2}, day2_2}, {{3, 1}, day3_1}};

  auto it = functions.find({day, part});
  if (it != functions.end()) {
    it->second();
  } else {
    std::cerr << "Day " << day << " Part " << part << " not implemented\n";
    return 1;
  }

  return 0;
}
