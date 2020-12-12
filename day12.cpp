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
using std::ceil;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::pair;
using std::set;
using std::queue;
using std::sqrt;
using std::string;
using std::forward_as_tuple;
using std::tie;
using std::tuple;
using std::swap;
using std::vector;

void day12() {
   static vector<int> xdirs({1,0,-1,0});
   static vector<int> ydirs({0,1,0,-1});

   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day12.txt");
   string line;
   int x=0;
   int y=0;
   int dir=0;
   while (getline(ifile, line)) {
      char c;
      int i;
      istringstream iline(line);
      iline >> c >> i;
      switch (c) {
         case 'N':
            y += i;
            break;
         case 'S':
            y -= i;
            break;
         case 'E':
            x+= i;
            break;
         case 'W':
            x -= i;
            break;
         case 'L':
            dir += i/90;
            break;
         case 'R':
            dir -= i/90;
            break;
         case 'F':
            dir %=4;
            dir += 4;
            dir %= 4;
            x += i * xdirs[dir];
            y += i * ydirs[dir];
            break;
      }
   }

   star1 = abs(x) + abs(y);
   cout << "Day 12 star 1 = " << star1 << "\n";
   cout << "Day 12 star 2 = " << star2 << "\n";
}
