#include <fstream>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::tuple;
using std::vector;

int countNeighbors(map<tuple<int, int, int>, char> &world, int w, int x,
                   int y) {
   int sum = 0;
   for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
         for (int k = -1; k <= 1; ++k) {
            if (i == 0 && j == 0 && k == 0)
               continue;
            if (world[{w + i, x + j, y + k}] == '#')
               ++sum;
         }
   return sum;
}

int countNeighbors(map<tuple<int, int, int, int>, char> &world, int w, int x,
                   int y, int z) {
   int sum = 0;
   for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
         for (int k = -1; k <= 1; ++k)
            for (int l = -1; l <= 1; ++l) {
               if (i == 0 && j == 0 && k == 0 && l == 0)
                  continue;
               if (world[{w + i, x + j, y + k, z + l}] == '#')
                  ++sum;
            }
   return sum;
}

void applyRule(int num, char &c) {
   if (c == '#') {
      if (num < 2 || num > 3)
         c = '.';
   } else if (num == 3)
      c = '#';
}

void day17() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day17.txt");

   vector<string> origMap;
   map<tuple<int, int, int>, char> world3d;
   map<tuple<int, int, int, int>, char> world4d;

   int lineNum = 0;
   string line;
   for (; getline(ifile, line); ++lineNum) {
      for (int x = 0; x < line.size(); ++x)
         world3d[{0, x, lineNum}] = world4d[{0, x, lineNum, 0}] = line[x];
   }
   int minf = 0;      //flat dimension
   int maxf = 1;      //flat dimension
   int mind = 0;      //dimension with data
   int maxd = lineNum;//dimension with data

   for (int gen = 0; gen < 6; ++gen) {
      auto oldWorld3d = world3d;
      auto oldWorld4d = world4d;
      --minf;
      --mind;
      ++maxf;
      ++maxd;
      for (int w = minf; w < maxf; ++w)
         for (int x = mind; x < maxd; ++x)
            for (int y = mind; y < maxd; ++y) {
               applyRule(countNeighbors(oldWorld3d, w, x, y),
                         world3d[{w, x, y}]);
               for (int z = minf; z < maxf; ++z)
                  applyRule(countNeighbors(oldWorld4d, w, x, y, z),
                            world4d[{w, x, y, z}]);
            }
   }
   for (auto &[loc, c] : world3d)
      if (c == '#')
         ++star1;
   for (auto &[loc, c] : world4d)
      if (c == '#')
         ++star2;

   cout << "Day 17 star 1 = " << star1 << "\n";
   cout << "Day 17 star 2 = " << star2 << "\n";
}
