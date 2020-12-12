#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

bool hasSum(const std::set<uint64_t> &s, uint64_t goal) {
   auto lower = s.begin();
   auto upper = s.end();
   --upper;
   while (lower != upper) {
      if (*lower + *upper == goal)
         return true;
      if (*lower + *upper < goal)
         ++lower;
      else if (*lower + *upper >= goal)
         --upper;
   }
   return false;
}

void day9() {
   std::ifstream ifile("../day9.txt");
   std::uint64_t i{};
   std::vector<uint64_t> nums;
   while (ifile >> i)
      nums.push_back(i);

   const int windowSize = 25;
   auto current = nums.begin() + windowSize;
   std::set<uint64_t> window(nums.begin(), current);
   for (; hasSum(window, *current); ++current) {
      window.erase(*(current-windowSize));
      window.insert(*current);
   }
   auto star1 = *current;

   auto l = nums.begin();
   auto r = nums.begin();
   auto total = uint64_t{0};
   while (total != star1 || r-l==1)
      if (total <= star1)
         total += *r++;
      else
         total -= *l++;

   auto [n1, n2] = std::minmax_element(l, r);
   auto star2 = *n1 + *n2;

   std::cout << "Day 9 star 1 = " << star1 << "\n"
             << "Day 9 star 2 = " << star2 << "\n";
}
// Day 9 star 1 = 375054920
// Day 9 star 2 = 54142584