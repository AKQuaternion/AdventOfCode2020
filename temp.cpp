//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <fstream>
//#include <iomanip>
//#include <iostream>
//#include <iterator>
//#include <map>
//#include <memory>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <string>
//#include <tuple>
//#include <utility>
//#include <vector>
//
//using std::cout;
//using std::ifstream;
//using std::istream;
//using std::istringstream;
//using std::map;
//using std::max;
//using std::max_element;
//using std::min;
//using std::pair;
//using std::queue;
//using std::set;
//using std::sqrt;
//using std::string;
//using std::swap;
//using std::tie;
//using std::tuple;
//using std::vector;
//
//int countNeighbors(map<tuple<int, int, int>, char> &world, int w, int x,
//                   int y) {
//   int sum = 0;
//   for (int i = -1; i <= 1; ++i)
//      for (int j = -1; j <= 1; ++j)
//         for (int k = -1; k <= 1; ++k) {
//            if (i == 0 || j == 0 || k == 0)
//               continue;
//            if (world[{w + i, x + j, y + k}] == '#')
//               ++sum;
//         }
//   return sum;
//}
//
//int countNeighbors(map<tuple<int, int, int, int>, char> &world, int w, int x,
//                   int y, int z) {
//   int sum = 0;
//   for (int i = -1; i <= 1; ++i)
//      for (int j = -1; j <= 1; ++j)
//         for (int k = -1; k <= 1; ++k)
//            for (int l = -1; l <= 1; ++l) {
//               if (i == 0 && j == 0 && k == 0 && l == 0)
//                  continue;
//               if (world[{w + i, x + j, y + k, z + l}] == '#')
//                  ++sum;
//            }
//   return sum;
//}
//
//void applyRule(int num, char &c) {
//   if (c == '#') {
//      if (num < 2 || num > 3)
//         c = '.';
//   } else if (num == 3)
//      c = '#';
//}
//
//void day17() {
//   auto star1 = 0;
//   auto star2 = 0;
//   ifstream ifile("../day17.txt");
//   string line;
//   vector<string> origMap;
//   while (getline(ifile, line)) {
//      origMap.push_back(line);
//   }
//
//   int minw = 0;
//   int maxw = 0;
//   int minx = 0;
//   int maxx = origMap[0].size();
//   int miny = 0;
//   int maxy = origMap.size();
//   int minz = 0;
//   int maxz = 0;
//
//   map<tuple<int, int, int>, char> world3d;
//   map<tuple<int, int, int, int>, char> world4d;
//   for (int y = 0; y < origMap.size(); ++y)
//      for (int x = 0; x < origMap[y].size(); ++x)
//         world3d[{x, y, 0}] = world4d[{0, x, y, 0}] = origMap[y][x];
//
//   for (int gen = 0; gen < 6; ++gen) {
//      auto oldWorld3d = world3d;
//      auto oldWorld4d = world4d;
//      --minw;
//      --minx;
//      --miny;
//      --minz;
//      ++maxw;
//      ++maxx;
//      ++maxy;
//      ++maxz;
//      for (int w = minw; w <= maxw; ++w)
//         for (int x = minx; x <= maxx; ++x)
//            for (int y = miny; y <= maxy; ++y) {
//               applyRule(countNeighbors(oldWorld3d, w, x, y),
//                         world3d[{w, x, y}]);
//               for (int z = minz; z <= maxz; ++z)
//                  applyRule(countNeighbors(oldWorld4d, w, x, y, z),
//                            world4d[{w, x, y, z}]);
//            }
//
//      for (auto &[loc, c] : world3d)
//         if (c == '#')
//            ++star1;
//
//      for (auto &[loc, c] : world4d)
//         if (c == '#')
//            ++star2;
//   }
//   cout << "Day 17 star 1 = " << star1 << "\n";
//   cout << "Day 17 star 2 = " << star2 << "\n";
//}