#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::string;
using std::vector;

void day5() {
   ifstream ifile("../day5.txt");
   string line;
   vector<int> ids;
   while (getline(ifile, line)) {
      int seat = 0;
      for (auto c : line) {
         seat *= 2;
         if (c == 'B' || c == 'R')
            ++seat;
      }
      ids.push_back(seat);
   }
   sort(ids.begin(), ids.end());
   auto star1 = ids.back();
   auto star2 = 0;
   for (int i = 0; i < ids.size() - 1; ++i)
      if (ids[i + 1] - ids[i] == 2)
         star2 = ids[i] + 1;

   cout << "Day 5 star 1 = " << star1 << "\n";
   cout << "Day 5 star 2 = " << star2 << "\n";
}
