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

void day6() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day6.txt");
   string line;
   set<char> ans;
   bool first=true;
   while (getline(ifile, line)) {
      if(line == "") {
         star2 += ans.size();
         ans.clear();
         first = true;
      }
      else {
         set<char> curPerson;
         for (auto c : line)
            curPerson.insert(c);
         if (first) {
            ans = curPerson;
            first = false;
         }
         else {
            vector<char> newAns;
            std::set_intersection(ans.begin(),ans.end(),curPerson.begin(),curPerson.end(),std::back_inserter(newAns));
            ans.clear();
            ans.insert(newAns.begin(),newAns.end());
         }
      }
   }

   cout << "Day 6 star 1 = " << star1 << "\n";
   cout << "Day 6 star 2 = " << star2 << "\n";
}
