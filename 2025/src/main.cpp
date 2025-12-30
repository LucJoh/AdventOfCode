#include <cstdlib>
#include <iostream>

void day1_1();
void day1_2();
void day2_1();
void day2_2();

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: run_day <day> <part>\n";
    return 1;
  }

  //    int day = std::atoi(argv[1]);
  int day = std::stoi(argv[1]);
  int part = std::stoi(argv[2]);

  switch (day) {
  case 1:
    if (part == 1) {
      day1_1();
    } else {
      day1_2();
    }
    break;
  case 2:
    if (part == 1) {
      day2_1();
    } else {
      day2_2();
    }
    break;
    //        case 3: day03(); break;
  default:
    std::cerr << "Day " << day << " not implemented\n";
    return 1;
  }
}
