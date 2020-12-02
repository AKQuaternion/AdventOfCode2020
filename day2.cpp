
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using std::abs;
using std::ceil;
using std::count;
using std::cout;
using std::endl;
using std::forward_as_tuple;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::pair;
using std::queue;
using std::set;
using std::sqrt;
using std::string;
using std::swap;
using std::tie;
using std::tuple;
using std::vector;

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
/*
 * 4-5 r: rrrjr
9-10 x: pxcbpxxwkqjttx
8-13 b: rjbbbbvgrbrfjx
 */