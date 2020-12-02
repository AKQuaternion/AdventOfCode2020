#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::string;

void day2() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day2.txt");
   string line;
   while (getline(ifile, line)) {
      string password;
      int min;
      int max;
      char _c;
      char letter;
      istringstream iline(line);
      iline >> min >> _c >> max >> letter >> _c >> password;
      auto num = count(password.begin(), password.end(), letter);
      if (min <= num && num <= max)
         ++star1;
      if ((password[min - 1] == letter && password[max - 1] != letter) ||
          (password[min - 1] != letter && password[max - 1] == letter))
         ++star2;
   }

   cout << "Day 2 star 1 = " << star1 << "\n";
   cout << "Day 2 star 2 = " << star2 << "\n";
}
