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
#include <optional>
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
using std::move;
using std::optional;
using std::pair;
using std::queue;
using std::set;
using std::sqrt;
using std::string;
using std::swap;
using std::tie;
using std::tuple;
using std::vector;

template<typename T>
T to(const string &s) {
   istringstream iline(s);
   T t;
   iline >> t;
   return t;
}


class GameConsole {
   struct Instruction {
      string _op;
      int _arg = 0;
   };

   struct Registers {
      int _pc = 0;
      int _acc = 0;

      void execute(const Instruction &i) {
         if (i._op == "nop")
            ++_pc;
         else if (i._op == "jmp")
            _pc += i._arg;
         else {
            _acc += i._arg;
            ++_pc;
         }
      }

      void executeSwapped(const Instruction &i) {
         if (i._op == "jmp")
            ++_pc;
         else if (i._op == "nop")
            _pc += i._arg;
         else {
            _acc += i._arg;
            ++_pc;
         }
      }
   };

private:
   Registers _r;
   vector<Instruction> _code;

public:
   explicit GameConsole(const string &filename) {
      ifstream ifile(filename);
      string line;
      while (getline(ifile, line)) {
         istringstream iline(line);
         Instruction i;
         iline >> i._op >> i._arg;
         _code.emplace_back(move(i));
      }
   }

   int runUntilLoop() {
      _r = {};
      vector<bool> hits(_code.size());
      while(!hits[_r._pc]) {
         hits[_r._pc] = true;
         _r.execute(_code[_r._pc]);
      }
      return _r._acc;
   }

   int unCorrupt() {
      _r = {};
      vector<bool> hits(_code.size());
      optional<Registers> hasBacktrack;
      while(true) {
         hits[_r._pc] = true;

         if(hasBacktrack) {
            _r.execute(_code[_r._pc]);
            if(_r._pc == _code.size())
               return _r._acc;
            if(hits[_r._pc]) {
               _r = *std::exchange(hasBacktrack, {}); //backtrack
               _r.execute(_code[_r._pc]); //execute original instruction
            }
         } else {
            hasBacktrack = _r;
            _r.executeSwapped(_code[_r._pc]);
         }
      }
      return _r._acc;
   }
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
   }
}

void day10b() {
   GameConsole game("../day10.txt");
   auto star1 = game.runUntilLoop();
   auto star2 = game.unCorrupt();

   std::cout << "Day 10 star 1 = " << star1 << "\n"
             << "Day 10 star 2 = " << star2 << "\n";

}
//Day 8 star 1 = 1594
//Day 8 star 2 = 758
