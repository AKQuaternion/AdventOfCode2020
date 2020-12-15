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
#include <unordered_map>
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
using std::unordered_map;
using std::vector;

void day15() {
   auto star1 = 0;
   auto star2 = 0;
   //   ifstream ifile("../day15.txt");
   //   string line;
   //   while (getline(ifile, line)) {
   //      string s;
   //      int i;
   //      int x;
   //      int y;
   //      char c;
   //      double d;
   //      istringstream iline(line);
   //      iline >> s;
   //   }

   vector<int> nums(30000000,-1);
   vector<int> input{7,12,1,0,16,2};
   for (int i = 0; i < input.size(); ++i)
      nums[input[i]] = i;
   int current = 0;
   for (int i = input.size(); i < 30000000; ++i) {
      int next = (nums[current] >= 0) ? i - nums[current] : 0;
      nums[current] = i;
      if (i == 2019)
         star1 = current;
      if (i == 30000000 - 1)
         star2 = current;
      current = next;
   }
   cout << "Day 15 star 1 = " << star1 << "\n";
   cout << "Day 15 star 2 = " << star2 << "\n";
}
