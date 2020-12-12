#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::move;
using std::optional;
using std::pair;
using std::set;
using std::string;
using std::vector;

namespace {
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
               execute({"nop", i._arg});
            else if (i._op == "nop")
               execute({"jmp", i._arg});
            else
               execute(i);
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
         while (!hits[_r._pc]) {
            hits[_r._pc] = true;
            _r.execute(_code[_r._pc]);
         }
         return _r._acc;
      }

      int unCorrupt() {
         _r = {};
         vector<bool> hits(_code.size());
         optional<Registers> stateBeforeSwap;
         while (true) {
            hits[_r._pc] = true;

            if (stateBeforeSwap) {//if we have swapped a jmp/nop
               _r.execute(_code[_r._pc]);
               if (_r._pc == _code.size())
                  return _r._acc;
               if (hits[_r._pc]) {
                  _r = *std::exchange(stateBeforeSwap, {});//backtrack
                  _r.execute(_code[_r._pc]);//execute original instruction
               }
            } else {
               const auto &currentInstruction = _code[_r._pc]._op;
               if (currentInstruction == "jmp" || currentInstruction == "nop")
                  stateBeforeSwap = _r;
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
}// namespace
void day8() {
   GameConsole game("../day8.txt");
   auto star1 = game.runUntilLoop();
   auto star2 = game.unCorrupt();

   std::cout << "Day 8 star 1 = " << star1 << "\n"
             << "Day 8 star 2 = " << star2 << "\n";
}
//Day 8 star 1 = 1594
//Day 8 star 2 = 758
