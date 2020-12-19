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

using std::string;

#include <deque>
using std::deque;
using std::uint64_t;

void mySize(deque<char> &s) {
   cout << s.size() << endl;
}

uint64_t eval(deque<char> &s, int star) {
   char op;
   uint64_t lval;
   uint64_t rval;
   if (s.front() == '(') {
      s.pop_front();
      lval = eval(s,star);
   } else {
      lval = s.front() - '0';
      s.pop_front();
   }
   while (!s.empty()) {
      op = s.front();
      s.pop_front();
      if (op == ')')
         return lval;
      if (star==2 && op == '*') // multiply for star2
         return lval * eval(s,star);
      if (s.front() == '(') {
         s.pop_front();
         rval = eval(s,star);
      } else {
         rval = s.front() - '0';
         s.pop_front();
      }
      if (op == '+')
         lval += rval;
      else  //multiply for star1
         lval *= rval;
   }
   return lval;
}

void day18() {
   uint64_t star1 = 0;
   uint64_t star2 = 0;
   ifstream ifile("../day18.txt");
   string line;
   while (getline(ifile, line)) {
      istringstream iline(line);
      char c;
      deque<char> t;
      while(iline>>c)
         t.push_back(c);
      auto tCopy = t;
      star1 += eval(tCopy,1);
      star2 += eval(t,2);
   }
   cout << "Day 18 star 1 = " << star1 << "\n";
   cout << "Day 18 star 2 = " << star2 << "\n";
}
