#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using std::abs;
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::string;
using std::swap;
using std::vector;

int star1(const vector<string> &instructions) {
   const vector<int> xdeltas({1,0,-1,0});
   const vector<int> ydeltas({0,1,0,-1});
   int x = 0;
   int y = 0;
   int dir = 0;
   for (const auto &line : instructions) {
      char c;
      int i;
      istringstream iline(line);
      iline >> c >> i;
      switch (c) {
         case 'N': y += i; break;
         case 'S': y -= i; break;
         case 'E': x += i; break;
         case 'W': x -= i; break;
         case 'L': dir += i / 90; break;
         case 'R': dir += 3*(i / 90); break;
         case 'F':
            dir %= 4;
            x += i * xdeltas[dir];
            y += i * ydeltas[dir];
            break;
         default:
            cout << "bad instruction character in star1()\n";
      }
   }
   return abs(x) + abs(y);
}

int star2(const vector<string> &instructions) {
   int x = 0;
   int y = 0;
   int dx = 10;
   int dy = 1;
   for (const auto &line : instructions) {
      char c;
      int i;
      istringstream iline(line);
      iline >> c >> i;
      switch (c) {
         case 'N': dy += i; break;
         case 'S': dy -= i; break;
         case 'E': dx += i; break;
         case 'W': dx -= i; break;
         case 'L':
            for (int j = 0; j < i / 90; ++j) {
               swap(dx, dy);
               dx *= -1;
            }
            break;
         case 'R':
            for (int j = 0; j < i / 90; ++j) {
               swap(dx, dy);
               dy *= -1;
            }
            break;
         case 'F':
            x += i * dx;
            y += i * dy;
            break;
         default:
            cout << "bad instruction character in star2()\n";
      }
   }
   return abs(x) + abs(y);
}

void day12() {
   ifstream ifile("../day12.txt");
   string line;
   vector<string> instructions;
   while (ifile >> line)
      instructions.push_back(line);
   cout << "Day 12 star 1 = " << star1(instructions) << "\n";
   cout << "Day 12 star 2 = " << star2(instructions) << "\n";
}
//Day 12 star 1 = 1441
//Day 12 star 2 = 61616