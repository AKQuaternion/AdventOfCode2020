#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using std::cout;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::pair;
using std::string;
using std::tuple;
using std::vector;

pair<int, int> find2Summands(const vector<int> &numbers, int desiredSum) {
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

tuple<int,int,int> find3Summands(const vector<int> &numbers, int desiredSum) {
   for(auto n : numbers)
      if(auto [x1,x2] = find2Summands(numbers,desiredSum-n); x1 >= 0)
         return {n,x1,x2};
return {-1,-1,-1};
}

void day1() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day1.txt");
   int i;
   vector<int> numbers;
   while (ifile >> i)
      numbers.push_back(i);

   sort(numbers.begin(), numbers.end());

   auto [x1,x2] = find2Summands(numbers,2020);
   star1 = x1 * x2;
   auto [y1,y2,y3] = find3Summands(numbers,2020);
   star2 = y1 * y2 * y3;

   cout << "Day 1 star 1 = " << star1 << "\n";
   cout << "Day 1 star 2 = " << star2 << "\n";
}
