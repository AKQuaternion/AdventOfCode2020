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


int countNeighbors( map<tuple<int,int,int>,char> &world, int x, int y, int z) {
   int sum = 0;
   for(int i=-1;i<=1;++i)
      for(int j=-1;j<=1;++j)
         for(int k=-1;k<=1;++k) {
            if (i==0&&j==0&&k==0)
               continue;
            if(world[{z+i,y+j,x+k}]=='#')
               ++sum;
         }
   return sum;
}

void day17() {
   auto star1 = 0;
   auto star2 = 0;
//   ifstream ifile("../day17.txt");
   ifstream ifile("../day17.txt");
   string line;
   vector<string> origMap;
   while (getline(ifile, line)) {
      origMap.push_back(line);
   }

   int minr = 0; int maxr = 0;
   int minz = 0; int maxz =0;
   int minx = 0; int maxx = origMap[0].size();
   int miny = 0; int maxy = origMap.size();

   map<tuple<int,int,int>,char> world;
   for(int i=0;i<origMap.size();++i)
      for(int j=0;j<origMap[i].size();++j)
         world[{0,i,j}] = origMap[i][j];

   for(int gen=0;gen<6;++gen) {
      auto worldOld = world;
      --minz; --miny; --minx; --minr;
      ++maxz; ++maxy; ++maxx; ++
      for(int z=minz;z<=maxz;++z)
         for(int y=miny;y<=maxy;++y)
            for(int x=minx;x<=maxx;++x) {
               //
               auto num = countNeighbors(worldOld, x, y, z);
               if (world[{z, y, x}] == '#') {
                  if (num == 2 || num == 3) {
                     ;
                  } else
                     world[{z, y, x}] = '.';
               } else if (num == 3)
                  world[{z, y, x}] = '#';
            }
   }
   for(auto &[loc,t] : world)
      if(t=='#')
         ++star1;

   cout << "Day 17 star 1 = " << star1 << "\n";
   cout << "Day 17 star 2 = " << star2 << "\n";
}
//If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active. Otherwise, the cube becomes inactive.
/// a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active. Otherwise, the cube remains inactive.