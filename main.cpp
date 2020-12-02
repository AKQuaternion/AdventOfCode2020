#include <chrono>
#include <iostream>

void day1();
void day2();
void day3();
void day4();
void day5();
void day6();
void day7();
void day8();
void day9();
void day10();
void day11();
void day12();
void day13();
void day14();
void day15();
void day16();
void day17();
void day18();
void day19();
void day20();
void day21();
void day22();
void day23();
void day24();
void day25();

// day 1
// day 2
// day 3
// day 4
// day 5
// day 6
// day 7
// day 8
// day 9
// day 10
// day 11
// day 12
// day 13
// day 14
// day 15
// day 16
// day 17
// day 18
// day 19
// day 20
// day 21
// day 22
// day 23
// day 24
// day 25


double timesec() {
  auto nanos = static_cast<std::chrono::nanoseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch());
  return static_cast<double>(nanos.count()) / 1.e9;
}

int main() {
  double time1 = timesec(); // End time (sec)

//      day1();
      day2();
  //    day3();
  //    day4();
  //    day5();
  //    day6();
  //    day7();
  //    day8();
  //    day9();
  //    day10();
  //    day11();
  //    day12();
  //    day13();
  //    day14();
  //    day15();
  //  day16();
  //  day17();
  //  day18();
  //  day19();
  //  day20();
  //  day21();
  //  day22();
  //  day23();
  //  day24();
  //  day25();
  double time2 = timesec();           // End time (sec)
  double elapsedtime = time2 - time1; // Elapsed (sec)
  std::cout << "Time required: " << elapsedtime << " seconds" << std::endl;
}
// Day 1 star 1 =
// Day 1 star 2 =
// Day 2 star 1 =
// Day 2 star 2 =
// Day 3 star 1 =
// Day 3 star 2 =
// Day 4 star 1 =
// Day 4 star 2 =
// Day 5 star 1 =
// Day 5 star 2 =
// Day 6 star 1 =
// Day 6 star 2 =
// Day 7 star 1 =
// Day 7 star 2 =
// Day 8 star 1 =
// Day 8 star 2 =
// Day 9 star 1 =
// Day 9 star 2 =
// Day 10 star 1 =
// Day 10 star 2 =
// Day 11 star 1 =
// Day 11 star 2 =
// Day 12 star 1 =
// Day 12 star 2 =
// Day 13 star 1 =
// Day 13 star 2 =
// Day 14 star 1 =
// Day 14 star 2 =
// Day 15 star 1 =
// Day 15 star 2 =
// Day 16 star 1 =
// Day 16 star 2 =
// Day 17 star 1 =
// Day 17 star 2 =
// Day 18 star 1 =
// Day 18 star 2 =
// Day 19 star 1 =
// Day 19 star 2 =
// Day 20 star 1 =
// Day 20 star 2 =
// Day 21 star 1 =
// Day 21 star 2 =
// Day 22 star 1 =
// Day 22 star 2 =
// Day 23 star 1 =
// Day 23 star 2 =
// Day 24 star 1 =
// Day 24 star 2 =