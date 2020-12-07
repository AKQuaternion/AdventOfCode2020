#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::map;
using std::pair;
using std::set;
using std::string;
using std::unordered_map;
using std::vector;

template <typename T, typename R>
using Map = unordered_map<T,R>;

class containsCounter {
private:
   set<string> visited;
   const Map<string,vector<string>> &edges;

   void dfs(const string &v) {
      visited.insert(v);
      if (edges.count(v))
         for (const string &s : edges.at(v))
            if (visited.count(s) == 0)
               dfs(s);
   }
public:
   explicit containsCounter(const Map<string,vector<string>> &edges):edges(edges) {}
   [[nodiscard]] int result() {
      dfs("shinygold");
      return visited.size();
   }
};


class BagCounter {
private:
   Map<string, int> contains; //memoize results
   const Map<string, vector<pair<string, int>>> &edges;

   int bagContains(string v) {
      if (contains.count(v) == 1)
         return contains.at(v);
      int sum = 1;
      if (edges.count(v) != 0) {
         for (const auto &[neighbor, count] : edges.at(v))
            sum += count * bagContains(neighbor);
      }
      contains[v] = sum;
      return sum;
   }
public:
   explicit BagCounter(const Map<string, vector<pair<string, int>>> &m):edges(m) {}
   [[nodiscard]] int result() {
      return bagContains("shinygold")-1;
   }
};

void day7() {
   Map<string, vector<pair<string, int>>> containsEdges;
   Map<string,vector<string>> isContainedInEdges;
   ifstream ifile("../day7.txt");
   string line;
   while (getline(ifile, line)) {
      string sa;
      string sc;
      string _s;
      istringstream iline(line);
      iline >> sa >> sc >> _s >> _s;
      string left = sa + sc;
      while (iline) {
         int i;
         iline >> i >> sa >> sc >> _s;
         if (iline) {
            containsEdges[left].push_back({sa + sc, i});
            isContainedInEdges[sa+sc].push_back(left);
         }
         else if (!iline.eof())
            containsEdges[left] = {};
      }
   }
   auto star2 = BagCounter(containsEdges).result();
   auto star1 = containsCounter(isContainedInEdges).result();
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