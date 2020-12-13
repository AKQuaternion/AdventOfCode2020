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

void day13() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day13.txt");
   int time;
   ifile >> time;
   string line;
   getline(ifile,line);
   getline(ifile,line);
   cout << line << endl;
   istringstream iline(line);
   int i;
   vector<int> nums;
   while (true) {
      char _c;
      int i;
      iline >> i;
//      cout << "|" << i << "|" << endl;
      if(!iline) {
         if(iline.eof())
            break;
         iline.clear();
         iline >> _c >> _c;
         continue;
      }
      iline >> _c;
      nums.push_back(i);
   }
   int small = 10000000;
   for(auto n:nums) {
      int div = time/n + 1;
      int wait = n*div - time ;
      if (wait<small) {
         small = wait;
         star1 = wait * n;
      }
      cout << wait << endl;
   }
   cout << "Day 13 star 1 = " << star1 << "\n";
   cout << "Day 13 star 2 = " << star2 << "\n";
}
