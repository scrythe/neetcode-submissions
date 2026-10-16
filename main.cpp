#include <stdio.h>
#include <vector>
using std::vector;

#include "Data Structures & Algorithms/duplicate-integer/submission-6.cpp"

int main() {
  vector<int> input = {-1000000000, 1000000000, 0, -1, 1};
  Solution solution;
  bool res = solution.hasDuplicate(input);
  printf("res: %b\n", res);
  return 0;
}
