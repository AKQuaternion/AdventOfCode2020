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

set<string> visited;
void dfs(const map<string, vector<string>> m, string v) {
   visited.insert(v);
   if (m.count(v))
      for (const string &s : m.at(v))
         if (visited.count(s) == 0)
            dfs(m, s);
}

void day7() {
   auto star1 = 0;
   auto star2 = 0;
   map<string, vector<string>> edges;
   ifstream ifile("../day7.txt");
   string line;
   while (getline(ifile, line)) {
      string sa, sc, _s;
      int i;
      istringstream iline(line);
      iline >> sa >> sc >> _s >> _s;
      string x = sa + sc;
      cout << x << " -> ";
      while (iline) {
         iline >> i;
         if (!iline)
            break;
         iline >> sa >> sc >> _s;
         string y = sa + sc;
         cout << y << " ";
         edges[y].push_back(x);
      }
      cout << endl;
   }
   dfs(edges, "shinygold");
   star1 = visited.size();
   cout << "Day 7 star 1 = " << star1 << "\n";
   cout << "Day 7 star 2 = " << star2 << "\n";
}
/*
 * light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.
 */