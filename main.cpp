#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include "Data Structures & Algorithms/two-integer-sum/submission.cpp"

int main() {
  Solution solution;
  vector<int> vec = {0, 1, 2, 3, 997, -10000, -9999};
  vector<int> res = solution.twoSum(vec, -19999);
  vector<int> expected_res = {5, 6};
  printf("expected_res: %d %d\n", expected_res[0], expected_res[1]);
  printf("res: %d %d\n", res[0], res[1]);
  assert(expected_res == res);
  return 0;
}
