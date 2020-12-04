#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using std::all_of;
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

bool checkInfo(const map<string, string> &info) {
   const auto fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
   return all_of(fields.begin(), fields.end(),
                 [&info](const auto &req) { return info.count(req) == 1; });
}

bool checkNum(const string &s, int len, int min, int max) {
   if (s.size() != len)
      return false;
   int i;
   istringstream line(s);
   line >> i;
   return (i >= min && i <= max);
}

bool checkInfo2(map<string, string> &info) {
   if (!checkInfo(info))
      return false;

   if (!checkNum(info["byr"], 4, 1920, 2002))
      return false;

   if (!checkNum(info["iyr"], 4, 2010, 2020))
      return false;

   if (!checkNum(info["eyr"], 4, 2020, 2030))
      return false;

   auto hgt = info["hgt"];
   auto unit = hgt.substr(hgt.size() - 2, 2);

   if (unit == "in") {
      if (!checkNum(hgt.substr(0, hgt.size() - 2), 2, 59, 76))
         return false;
   } else if (unit == "cm") {
      if (!checkNum(hgt.substr(0, hgt.size() - 2), 3, 150, 193))
         return false;
   } else
      return false;

   if (info["hcl"][0] != '#')
      return false;

   if (!all_of(info["hcl"].begin() + 1, info["hcl"].begin() + 7,
               [](auto c) { return isxdigit(c); }))
      return false;

   auto eyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
   if (std::find(eyeColors.begin(), eyeColors.end(), info["ecl"]) ==
       eyeColors.end())
      return false;

   if (!checkNum(info["pid"], 9, 0, 999999999))
      return false;

   return true;
}

void day4() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day4.txt");
   string line;
   char _c;
   int _i;
   int x;
   int y;
   double d;
   map<string, string> info;
   while (getline(ifile, line)) {
      if (line == "") {
         if (checkInfo(info))
            ++star1;
         if (checkInfo2(info))
            ++star2;
         info.clear();
      }
      string _s;
      istringstream iline(line);
      while (iline >> _s) { info[_s.substr(0, 3)] = _s.substr(4, _s.size()); }
   }

   cout << "Day 4 star 1 = " << star1 << "\n";
   cout << "Day 4 star 2 = " << star2 << "\n";
}
