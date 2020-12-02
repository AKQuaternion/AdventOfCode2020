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

void day1() {
   auto star1 = 0;
   auto star2 = 0;
   ifstream ifile("../day1.txt");
   int _i;
   vector<int> numbers;
   while (ifile >> _i) {
      numbers.push_back(_i);
   }

   sort(numbers.begin(),numbers.end());
   auto low = 0;
   auto high = numbers.size()-1;
   while(true) {
      auto val = numbers[low]+numbers[high];
      if (val==2020) {
         star1 = numbers[low]*numbers[high];
         break;
      }
      else if (val < 2020)
         ++low;
      else
         --high;
   }
   for(unsigned long i=0;i<numbers.size();++i)
      for(unsigned long j=i+1;j<numbers.size();++j)
         for(unsigned long k=j+1;k<numbers.size();++k)
            if(numbers[i]+numbers[j]+numbers[k]==2020)
               cout << numbers[i]*numbers[j]*numbers[k];
            cout << "Day 1 star 1 = " << star1 << "\n";
   cout << "Day 1 star 2 = " << star2 << "\n";
}
