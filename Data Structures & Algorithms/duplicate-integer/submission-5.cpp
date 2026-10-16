#include <stdint.h>

#define assert(val)                                                            \
  if (!(val)) {                                                                \
    __builtin_trap();                                                          \
  }

typedef uint32_t u32;
typedef int32_t i32;

const int MAX_LENGTH = 1e5;
const int MAX_OFFSETTED_NUMBERS =
    2e9 + 2; // -10^9 to 10^9, 0 should not be a value

class Solution {
public:
  bool hasDuplicate(vector<int> &nums) {
    u32 items[MAX_LENGTH] = {};
    for (i32 key : nums) {
      u32 hashed_key = key + 1e9 + 1; // 0 should not be used
      assert(hashed_key != 0);
      u32 boxed_key = hashed_key % MAX_LENGTH;
      u32 i = boxed_key;
      while (true) {
        if (items[i] == hashed_key) {
          return true;
        } else if (items[i] != 0) {
          i += 1;
        } else {
          items[i] = hashed_key;
          break;
        }
      }
    }
    return false;
  }
};