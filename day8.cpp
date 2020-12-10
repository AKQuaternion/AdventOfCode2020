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

template <typename T>
T to(const string &s) {
   istringstream iline(s);
   T t;
   iline >> t;
   return t;
}

struct Instruction {
   string _op;
   int _arg;
};

class GameConsole {

struct Registers {
   int _pc;
   int _acc;
};
};

pair<bool, int> runCode(const vector<string> &ops, const vector<int> &is) {
   set<int> pcs;
   int pc = 0;
   int a = 0;
   while (true) {
      //      cout << pc << ops[pc] << is[pc] << endl;
      if (pcs.count(pc))
         return {true, a};
      if (pc == ops.size())
         return {false, a};
      pcs.insert(pc);
      if (ops[pc] == "nop")
         ++pc;
      else if (ops[pc] == "jmp")
         pc += is[pc];
      else {
         a += is[pc];
         ++pc;
      }
   }
}

void day8() {
   auto star2 = 0;
   ifstream ifile("../day8.txt");
   string line;
   vector<string> ops;
   vector<int> is;
   while (getline(ifile, line)) {
      string s;
      int i;
      istringstream iline(line);
      iline >> s >> i;
      ops.push_back(s);
      is.push_back(i);
   }

   auto [res, star1] = runCode(ops, is);
   cout << "Day 8 star 1 = " << star1 << "\n";


   for (int i = 0; i < ops.size(); ++i) {
      auto ops2 = ops;
      if (ops2[i] == "jmp")
         ops2[i] = "nop";
      else if (ops2[i] == "nop")
         ops2[i] = "jmp";
      auto [res, star2] = runCode(ops2, is);
      if (!res) {
         cout << "Day 8 star 2 = " << star2 << "\n";
         break;
      }
   }
}
/*
 * nop +0  | 1
acc +1  | 2, 8(!)
jmp +4  | 3
acc +3  | 6
jmp -3  | 7
acc -99 |
acc +1  | 4
jmp -4  | 5
acc +6
 */