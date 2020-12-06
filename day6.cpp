#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
using std::cout;
using std::ifstream;
using std::set;
using std::string;

void day6() {
   auto star1 = 0;
   auto star2 = 0;
   string groupAllYes = "abcdefghijklmnopqrstuvwxyz";
   set<char> groupAnyYes;

   ifstream ifile("../day6.txt");
   string line;
   while (getline(ifile, line)) {
      if (line.empty() || ifile.eof()) {
         star1 += groupAnyYes.size();
         groupAnyYes.clear();
         star2 += groupAllYes.size();
         groupAllYes = "abcdefghijklmnopqrstuvwxyz";
      } else {
         groupAnyYes.insert(line.begin(), line.end());
         sort(line.begin(),line.end());
         string intersection;
         set_intersection(groupAllYes.begin(),groupAllYes.end(),
                               line.begin(),line.end(),
                               back_inserter(intersection));
         groupAllYes = intersection;
      }
   }
   cout << "Day 6 star 1 = " << star1 << "\n";
   cout << "Day 6 star 2 = " << star2 << "\n";
}
