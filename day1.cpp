#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::pair;
using std::string;
using std::vector;

pair<int, int> findSummands(const vector<int> &numbers, int desiredSum) {
   auto low = numbers.begin();
   auto high = numbers.end() - 1;
   while (low <= high) {
      auto currentSum = *low + *high;
      if (currentSum == desiredSum)
         return {*low, *high};
      if (currentSum > desiredSum)
         --high;
      else
         ++low;
   }
   return {-1, -1};
}

void day1() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day1.txt");
   int i;
   vector<int> numbers;
   while (ifile >> i) {
      numbers.push_back(i);
   }

   sort(numbers.begin(), numbers.end());

   auto [x1,x2] = findSummands(numbers,2020);
   star1 = x1 * x2;
   for(auto n : numbers) {
      auto [x1,x2] = findSummands(numbers,2020-n);
      if( x1 >= 0) {
         star2 = x1 * x2 * n;
         break;
      }
   }

   cout << "Day 1 star 1 = " << star1 << "\n";
   cout << "Day 1 star 2 = " << star2 << "\n";
}
