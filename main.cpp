#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include "anagram_group.cpp"

int main() {
  Solution solution;
  vector<string> vec = {"act", "pots", "tops", "cat", "stop", "hat"};
  vector<vector<string>> res = solution.groupAnagrams(vec);
  vector<vector<string>> expected_res = {
      {"hat"}, {"act", "cat"}, {"stop", "pots", "tops"}};
  printf("res: ");
  for (vector<string> strs : res) {
    for (string str : strs) {
      printf("%s", str.c_str());
    }
  }
  return 0;
}
