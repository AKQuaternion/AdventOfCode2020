#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::string;
using std::vector;

auto countTrees(const vector<string> &treeMap, int x, int y) {
   auto ret = 0UL;
   auto sx = 0;
   auto sy = 0;
   while (sy < treeMap.size()) {
      sx += x;
      sy += y;
      sx %= treeMap.front().size();
      if (treeMap[sy][sx] == '#') ++ret;
   }
   return ret;
}

void day3() {
   ifstream ifile("../day3.txt");
   string line;
   vector<string> treeMap;
   while (getline(ifile, line))
      treeMap.push_back(line);

   auto star1 = countTrees(treeMap, 3, 1);

   auto star2 = countTrees(treeMap, 1, 1) * countTrees(treeMap, 3, 1) *
           countTrees(treeMap, 5, 1) * countTrees(treeMap, 7, 1) *
           countTrees(treeMap, 1, 2);

   cout << "Day 3 star 1 = " << star1 << "\n";
   cout << "Day 3 star 2 = " << star2 << "\n";
}
