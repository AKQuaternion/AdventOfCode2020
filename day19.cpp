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
using std::binary_search;
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

map<int, vector<vector<int>>> rules;

vector<string> validStrings(int i);

vector<string> validStringsOneChoice(const vector<int> &v) {
   if (v.size() == 1)
      return validStrings(v[0]);
   vector<string> p1 = validStrings(v[0]);
   vector<string> p2 = validStrings(v[1]);
   vector<string> ret;
   for (const string &s1 : p1)
      for (const string &s2 : p2)
         ret.emplace_back(s1 + s2);
   return ret;
}

vector<string> validStrings(int i) {
   static map<int, vector<string>> memo(
         {{-1, vector<string>({"a"})}, {-2, vector<string>({"b"})}});
   if(memo.count(i))
      return memo[i];
   if (i == -1)
      return {"a"};
   if (i == -2)
      return {"b"};
   vector<string> ret;
   for (const auto &choice : rules[i]) {
      auto validThisRule = validStringsOneChoice(choice);
      ret.insert(ret.end(), validThisRule.begin(), validThisRule.end());
   }
   memo[i]=ret;
   return ret;
}

void day19() {
   auto star1 = 0;
   auto star2 = 0;
   //   vector<Rule> rules;
   ifstream ifile("../day19.txt");
   string line;
   while (getline(ifile, line)) {
      if (line.empty())
         break;
      string s;
      int ruleNum;
      char _c;
      istringstream iline(line);
      iline >> ruleNum >> _c;
      rules[ruleNum].push_back({});
      while (iline >> s) {
         if (s == "|") {
            rules[ruleNum].push_back({});
            continue;
         }
         if (s == "\"a\"")
            s = "-1";
         else if (s == "\"b\"")
            s = "-2";
         rules[ruleNum].back().push_back(stoi(s));
      }
   }
   auto goodStringsStar1 = validStrings(0);
   sort(goodStringsStar1.begin(), goodStringsStar1.end());

   //For star 2:
   //As you look over the list of messages, you realize your matching rules
   // aren't quite right. To fix them, completely replace rules 8: 42 and
   // 11: 42 31 with the following:
   //
   // 8: 42 | 42 8
   // 11: 42 31 | 42 11 31
   // So the new 8 is "one or more 42s"
   // and the new 11 is 42^n 31^n
   // And valid strings for star 2 are thus 42^m 31^n with 1 <= n < m

   auto rule31 = validStrings(31);
   sort(rule31.begin(), rule31.end());
   auto rule42 = validStrings(42);
   sort(rule42.begin(), rule42.end());

   while (getline(ifile, line)) {
      if (binary_search(goodStringsStar1.begin(), goodStringsStar1.end(), line))
         ++star1;
      int num42 = 0;
      int num31 = 0;
      for (int i = 0; i < line.size() / 8; ++i) {
         auto chunki = line.substr(i * 8, 8);
         if (num31 == 0 && binary_search(rule42.begin(), rule42.end(), chunki))
            ++num42;
         else if (binary_search(rule31.begin(), rule31.end(), chunki))
            ++num31;
         else
            break;
      }
      if (1<=num31 && num31 < num42) {
         ++star2;
      }
   }

   cout << "Day 19 star 1 = " << star1 << "\n";
   cout << "Day 19 star 2 = " << star2 << "\n";
}
//0: 4 1 5
//1: 2 3 | 3 2
//2: 4 4 | 5 5
//3: 4 5 | 5 4
//4: "a"
//5: "b"
//
//ababbb
//bababa
//abbbab
//aaabbb
//aaaabbb