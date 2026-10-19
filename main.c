#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef struct {
  u8 *ptr;
  u32 len;
} string;

typedef struct {
  string *ptr;
  u32 len;
} slice_string;

typedef struct {
  slice_string *ptr;
  u32 len;
} slice_slice_string;

#include "anagram_group.c"

#define create_string(c_string)                                                \
  {.ptr = (u8 *)c_string, .len = sizeof(c_string) - 1}
#define create_slice_string(...)                                               \
  {                                                                            \
      .ptr = (string[]){__VA_ARGS__},                                          \
      .len = sizeof((string[]){__VA_ARGS__}) / sizeof(string),                 \
  }

int main() {
  slice_string vec = create_slice_string(
      create_string("act"), create_string("pots"), create_string("tops"),
      create_string("cat"), create_string("stop"), create_string("hat"));
  slice_slice_string res = {
      .ptr = malloc(vec.len * sizeof(slice_string)),
      .len = vec.len,
  };
  groupAnagrams(vec, res);
  // vector<vector<string>> expected_res = {
  //     {"hat"}, {"act", "cat"}, {"stop", "pots", "tops"}};
  // printf("res: ");
  // for (vector<string> strs : res) {
  //   for (string str : strs) {
  //     printf("%s", str.c_str());
  //   }
  // }
  return 0;
}
