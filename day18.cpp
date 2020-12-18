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
#include <deque>
using std::deque;

void mySize(deque<char> &s) {
   cout << s.size() << endl;
}

long long eval(deque<char> &s) {
//   cout << s.size() << endl;
   char op;
   long long lval;
   long long rval;
   if (s.front() == '(') {
      s.pop_front();
      lval = eval(s);
//      return lval;
   } else {
      lval = s.front() - '0';
      s.pop_front();
   }
   while (true) {
      if(s.empty())
         return lval;
      op = s.front();
      s.pop_front();
      if (op == ')')
         return lval;
      if (s.front() == '(') {
         s.pop_front();
         rval = eval(s);
      } else {
         rval = s.front() - '0';
         s.pop_front();
      }
      if (op == '+')
         lval += rval;
      else if (op == '*')
         lval *= rval;
      else throw "error";
   }
}

void day18() {
   unsigned long long star1 = 0;
   unsigned long long star2 = 0;
   ifstream ifile("../day18.txt");
   string line;
   while (getline(ifile, line)) {
      istringstream iline(line);
      char c;
      deque<char> t;
      while(iline>>c)
         t.push_back(c);
      auto t2 = t;
      cout << string(t2.begin(),t2.end()) << " = " << eval(t2) << endl;
      star1 += eval(t);
   }
//   string line2 = "(3*(4*8)*5*7*3)+8";
//   istringstream iline(line2);
//   char c;
//   deque<char> t;
//   while(iline>>c)
//      t.push_back(c);
//   string out(t.begin(),t.end());
//   auto n = eval(t);
//   cout << out << " " << n << endl;
   cout << "Day 18 star 1 = " << star1 << "\n";
   cout << "Day 18 star 2 = " << star2 << "\n";
}
//(3 * (4 * 8) * 5 * 7 * 3) + 8
//4 * (6 * 4 * 6) + 8 + 4
//(5 + 7) * 2 * 4 + 6 + 7 + (2 + 2 + 6 + (9 + 3 + 7 * 3))]\
// 2110836289 too low
// Not 10686381261