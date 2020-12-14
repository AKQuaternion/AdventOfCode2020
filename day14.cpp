#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;

map<long long, long long> star2memory;

void handleStar2Mask(const string &mask, long long m, long long v, int i) {
   if (i == 36) { // base caase
      star2memory[m] = v;
      return;
   }
   if (mask[i] == '0')
      handleStar2Mask(mask, m, v, i + 1); //handle next bit
   else if (mask[i] == '1') {
      m |= (1LL << i);  //set bit i in memory location
      handleStar2Mask(mask, m, v, i + 1);
   } else {
      m |= (1LL << i);  //set bit i in memory location
      handleStar2Mask(mask, m, v, i + 1);
      m &= ~(1LL << i); //clear bit i in memory location
      handleStar2Mask(mask, m, v, i + 1);
   }
}

void day14() {
   long long star1 = 0;
   long long star2 = 0;
   map<long long, long long> star1memory;

   ifstream ifile("../day14.txt");
   string line;
   string mask;
   while (getline(ifile, line)) {
      string s;
      istringstream iline(line);
      iline >> s;
      if (s == "mask") {
         iline >> s >> s; // skip "="
         mask = string(s.rbegin(), s.rend()); //reverse so mask[i] is 2^i
      } else {
         istringstream reader(s.substr(4)); // skip "mem[" four characters
         long long loc;
         reader >> loc;
         long long value;
         iline >> s >> value; // skip "="
         handleStar2Mask(mask, loc, value, 0);
         for(int i=0;i<36;++i) {
            if(mask[i]=='0')
               value &= ~(1ll<<i); // clear bit i in value
            else if (mask[i]=='1')
               value |= (1ll<<i);  // set bit i in value
         }
         star1memory[loc] = value;
      }
   }

   for (auto [m, v] : star1memory)
      star1 += v;
   for (auto [m, v] : star2memory)
      star2 += v;
   cout << "Day 14 star 1 = " << star1 << "\n";
   cout << "Day 14 star 2 = " << star2 << "\n";
}