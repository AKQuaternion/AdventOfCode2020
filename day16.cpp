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
#include <deque>
using std::deque;

void day16() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day16.txt");
   string line;
   map<string, vector<bool>> fields;
   while (getline(ifile, line)) {
      if(line.empty())
         break;
      string s;
      string name;
      int i;
      int j;
      int x;
      int y;
      char c;
      double d;
      istringstream iline(line);
      while(true) {
         iline >> s;
         name += s;
         if (s.back() == ':') {
            s.pop_back();
            break;
         }
      }
      fields[name] = vector<bool>(1000);
      cout << name << " ";
      //class: 1-3 or 5-7
      int b,e;
      iline >> b >> c >> e >> s;
      cout << b << "-" << e << " ";
      for(int i=b;i<=e;++i)
         fields[name][i]=true;
      iline >> b >> c >> e;
      cout << b << "-" << e << " ";
      for(int i=b;i<=e;++i)
         fields[name][i]=true;
      cout << endl;

   }
   getline(ifile,line); //read "your ticket:"
   getline(ifile,line); //read "your ticket:"
   istringstream tline(line);
   int t;
   vector<int> tnums;
   while (tline >> t)
   {
      char _c;
      tnums.push_back(t);
      tline >> _c;
   }
   cout << "Ticket has " << tnums.size() << endl;
   getline(ifile,line); //read "your ticket:"

   map<string,deque<bool>> nameToFnum;
   for(auto &[name,valid] : fields)
      nameToFnum[name] = deque<bool>(fields.size(),true);

   while (getline(ifile, line)) {
//      cout << "tickt " << line << endl;
      if(line.empty())
         break;
      string s;
      int i;
      int x;
      int y;
      char c;
      double d;
      istringstream iline(line);
      int fnum = 0;
      while (iline >> i) {
         bool okay = false;
//         cout << "checking " << i << endl;
         for(const auto &[name,valid] : fields) {
            if (valid[i])
               okay = true;
            else {
               nameToFnum[name][fnum] = false;
               if (name == "departurelocation:")
               cout << line << endl << i << " (pos) " << fnum << " can't fit field " << name << endl;
            }
         }
         if (!okay)
            star1 += i;
         iline >> c;
         ++fnum;
      }
   }

   for(auto &[name,poss] : nameToFnum) {
      cout << name << " can be fields ";
      for (int i = 0; i < poss.size(); ++i) {
         if (poss[i])
            cout << i << " ";
      }
      cout << endl;
   }

//   while (getline(ifile, line)) {
//      string s;
//      int i;
//      int x;
//      int y;
//      char c;
//      double d;
//      istringstream iline(line);
//   }

   cout << "Day 16 star 1 = " << star1 << "\n";
   cout << "Day 16 star 2 = " << star2 << "\n";
}
//class: 0-1 or 4-19
//row: 0-5 or 8-19
//seat: 0-13 or 16-19
//
//your ticket:
//11,12,13
//
//nearby tickets:
//3,9,18
//15,1,5
//5,14,9