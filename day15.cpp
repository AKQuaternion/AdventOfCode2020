#include <algorithm>
#include <array>
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

//std::array<int,30000001> numsv;
int numsv[30000001];
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

   for(int i=0;i<30000001;++i)
      numsv[i]=-1;
   //   unordered_map<int, int> nums;
   //         map<int,int> nums;
   //   nums.reserve(3700000);
   vector<int> input{0, 7, 12, 1, 0, 16, 2};
   for (int i = 0; i < input.size(); ++i)
      numsv[input[i]] = i;
   int currentv = 0;
   int nextv = -1;
   //   int current = 0;
   //   int next = -1;
   for (int i = input.size(); i < 30000001; ++i) {
      nextv = (numsv[currentv] >= 0) ? i - numsv[currentv] : 0;
//      cout << currentv << endl;
      //      auto &curInCache = nums[current];
      //      int next = (curInCache != 0) ? i - curInCache : 0;
      //      curInCache = i;
      numsv[currentv] = i;
      //            auto iterToCurrent = nums.find(current);
      //            if (iterToCurrent != nums.end()) {
      //               next = i - iterToCurrent->second;
      //            } else
      //               next = 0;
      //            nums.insert_or_assign(iterToCurrent,current,i);
      currentv = nextv;
      if (i == 2020-1)
         star1 = currentv;
      if (i == 30000000-1)
         star2 = currentv;
      //      if(next == 0)
      //            cout << current << endl;
      //      current = next;
   }
   //   cout << count_if(nums.begin(),nums.end(),[](auto i){return i != -1;}) << endl;
   //   cout << nums.size();
   cout << "Day 15 star 1 = " << star1 << "\n";
   cout << "Day 15 star 2 = " << star2 << "\n";
   //   nums.clear();
   cout << "Done"
        << "\n";
}
//6: 0 30000000
//7: 3 30000000
//8: 0 30000000
//9: 2 30000000
//10: 4 30000000
//11: 0 30000000
//12: 3 30000000
//13: 5 30000000
//14: 0 30000000
//15: 3 30000000
//16: 3 30000000
//17: 1 30000000
//18: 15 30000000