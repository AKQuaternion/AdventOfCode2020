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

void day10() {
   auto star1 = 0;
//   auto star2 = 0;
   ifstream ifile("../day10.txt");
   string line;
   vector<int> ads(1);
   int i;
   while (ifile >> i) {
      ads.push_back(i);
   }

//   star2 =ads.back();
   sort(ads.begin(),ads.end());
   int d1=0,d3=0;
   for(int i=0;i<ads.size()-1;++i) {
      if(ads[i+1]-ads[i] == 3)
         ++d3;
      if(ads[i+1]-ads[i] == 1)
         ++d1;
   }
   star1 = d1*(d3+1);

   vector<std::uint64_t > ways(ads.size());
   ways[0]=1;
   for(int ii=1;ii<ways.size();++ii) {
      if(ads[ii]-ads[ii-1]<=3)
         ways[ii] += ways[ii-1];
      if(ii>=2 && ads[ii]-ads[ii-2]<=3)
         ways[ii] += ways[ii-2];
      if(ii>=3 && ads[ii]-ads[ii-3]<=3)
         ways[ii] += ways[ii-3];
   }
//   for(auto w:ads)
//      cout << w << " ";
//   cout << endl;
//   for(auto w:ways)
//      cout << w << " ";
//   cout << endl;
   auto star2 = ways.back();
   cout << "Day 10 star 1 = " << star1 << "\n";
   cout << "Day 10 star 2 = " << star2 << "\n";

}
