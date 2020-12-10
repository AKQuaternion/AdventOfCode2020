#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

void day10() {
   ifstream ifile("../day10.txt");
   vector<int> adapters({0});//start with 0 jolts
   int num;
   while (ifile >> num)
      adapters.push_back(num);

   sort(adapters.begin(), adapters.end());

   std::array<int, 4> diffs{};
   for (int i = 0; i < adapters.size() - 1; ++i)
      ++diffs[adapters[i + 1] - adapters[i]];
   ++diffs[3];
   auto star1 = diffs[1] * diffs[3];

   vector<std::uint64_t> numWays(adapters.size());
   numWays[0] = 1;
   numWays[1] = 1;
   numWays[2] = adapters[2] <= 3 ? 2 : 1;
   for (int ii = 3; ii < numWays.size(); ++ii)
      for (int jj = 1; jj <= 3; ++jj)
         if (adapters[ii] - adapters[ii - jj] <= 3)
            numWays[ii] += numWays[ii - jj];

   auto star2 = numWays.back();
   cout << "Day 10 star 1 = " << star1 << "\n";
   cout << "Day 10 star 2 = " << star2 << "\n";
}
//Day 10 star 1 = 2232
//Day 10 star 2 = 173625106649344