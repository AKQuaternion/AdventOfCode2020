#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using std::all_of;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

void day16() {
   char _c;//for reading commas
   auto star1 = 0;
   ifstream ifile("../day16.txt");
   string line;
   map<string, vector<bool>> fields;
   while (getline(ifile, line)) {
      if (line.empty())
         break;
      string s;
      string name;
      istringstream iline(line);
      getline(iline, name, ':');
      fields[name] = vector<bool>(1000);
      int b, e;
      iline >> b >> _c >> e >> s;
      for (int i = b; i <= e; ++i)
         fields[name][i] = true;
      iline >> b >> _c >> e;
      for (int i = b; i <= e; ++i)
         fields[name][i] = true;
   }
   getline(ifile, line);//read "your ticket:"
   getline(ifile, line);//read ticket numbers
   istringstream tline(line);
   int t;
   vector<int> tnums;
   while (tline >> t) {
      tnums.push_back(t);
      tline >> _c;
   }
   getline(ifile, line);//read blank line

   map<string, vector<bool>> nameToFnum;
   for (auto &[name, valid] : fields)
      nameToFnum[name] = vector<bool>(fields.size(), true);

   vector<string> goodLines;
   while (getline(ifile, line) && !line.empty()) {
      istringstream iline(line);
      bool goodLine = true;
      int i;
      while (iline >> i) {
         if (all_of(fields.begin(), fields.end(),
                         [i](const auto &valid) { return !valid.second[i]; })) {
            star1 += i;
            goodLine = false;
         }
         iline >> _c;
      }
      if (goodLine) {
         iline.str(line);
         iline.clear();
         for (int fnum = 0; iline >> i; ++fnum) {
            for (const auto &[name, valid] : fields)
               if (!valid[i])
                  nameToFnum[name][fnum] = false;
            iline >> _c;
         }
      }
   }

   map<string, int> fieldNums;
   while (fieldNums.size() < tnums.size()) {
      for (auto &[name, poss] : nameToFnum) {
         auto num = std::count(poss.begin(), poss.end(), true);
         if (num == 1) {
            fieldNums[name] =
                  find(poss.begin(), poss.end(), true) - poss.begin();
            for (auto &[n2, p2] : nameToFnum)
               p2[fieldNums[name]] = false;
            break;
         }
      }
   }

   auto star2 = 1LL;
   for (auto &[n, i] : fieldNums)
      if (n.substr(0, 9) == "departure")
         star2 *= tnums[i];

   cout << "Day 16 star 1 = " << star1 << "\n";
   cout << "Day 16 star 2 = " << star2 << "\n";
}
//Day 16 star 1 = 27802
//Day 16 star 2 = 279139880759