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
using std::vector;

void day14() {
   long long star1 = 0;
   long long star2 = 0;
   ifstream ifile("../day14.txt");
   string line;
   string mask;
   map<long long, long long> memory;
   while (getline(ifile, line)) {
      string s;
      int i;
      int x;
      int y;
      char c;
      double d;
      istringstream iline(line);
      iline >> s;
      if (s == "mask") {
         iline >> s >> s;
         cout << s << endl;
         mask = string(s.rbegin(), s.rend());
      } else {
         istringstream reader(s.substr(4));
         long long loc;
         reader >> loc;
         long long value;
         iline >> s >> value;
         cout << loc << " " << value << endl;
         for(int i=0;i<36;++i) {
            if(mask[i]=='0')
               value &= ~(1ll<<i);
            else if (mask[i]=='1')
               value |= (1ll<<i);
         }
         cout << "new " << value << endl;
         memory[loc] = value;
      }
   }
   for(auto [m,v]:memory)
      star1 += v;
   cout << "Day 14 star 1 = " << star1 << "\n";
   cout << "Day 14 star 2 = " << star2 << "\n";
}
//mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X
//mem[8] = 11
//mem[7] = 101
//mem[8] = 0