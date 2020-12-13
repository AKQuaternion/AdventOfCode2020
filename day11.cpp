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

vector<string> seats;

int ct(int i, int j) {
   if (i < 0)
      return 0;
   if (i >= seats[0].size())
      return 0;
   if (j < 0)
      return 0;
   if (j >= seats.size())
      return 0;
   if (seats[j][i] == '#')
      return 1;
   return 0;
}

int ct2(int i, int j, int di, int dj) {
   int x = i + di;
   int y = j + dj;
   while (x >= 0 && x < seats[0].size() && y >= 0 && y < seats.size() &&
          seats[y][x] == '.') {
      x += di;
      y += dj;
   }
   if (x >= 0 && x < seats[0].size() && y >= 0 && y < seats.size())
      return seats[y][x] == '#' ? 1 : 0;
   return 0;
}

void day11() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day11.txt");
   string line;
   while (getline(ifile, line)) {
      seats.emplace_back(line);
   }

   while (true) {
      vector<string> seats2(seats);
      for (int j = 0; j < seats.size(); ++j)
         for (int i = 0; i < seats[0].size(); ++i) {
            int sum = 0;
            sum += ct2(i, j, -1, -1);
            sum += ct2(i, j, -1, 0);
            sum += ct2(i, j, -1, 1);
            sum += ct2(i, j, 1, -1);
            sum += ct2(i, j, 1, 0);
            sum += ct2(i, j, 1, 1);
            sum += ct2(i, j, 0, -1);
            sum += ct2(i, j, 0, 1);
            if (seats2[j][i] == 'L' && sum == 0)
               seats2[j][i] = '#';
            if (seats2[j][i] == '#' && sum >= 5)
               seats2[j][i] = 'L';
         }

      //      cout << s << endl;
      //      cout << endl;
      if (seats2 == seats)
         break;
      seats = seats2;
   }
   for (auto s : seats)
      star1 += count(s.begin(), s.end(), '#');

   cout << "Day 11 star 1 = " << star1 << "\n";
   cout << "Day 11 star 2 = " << star2 << "\n";
}
