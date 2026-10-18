#include <stdint.h>
#include <stdio.h>

typedef int32_t i32;
typedef uint32_t u32;

typedef struct {
  i32 *ptr;
  u32 length;
} i32Slice;

#define array_length(array) sizeof(array) / sizeof(*array)

#include "Data Structures & Algorithms/two-integer-sum/submission.c"

int main() {
  i32 vec_array[] = {0, 1, 2, 3, 997, -10000, -9999};
  i32Slice vec = {.ptr = vec_array, .length = array_length(vec_array)};
  Res res = twoSum(vec, -19999);
  Res expected_res = {.i = 5, .j = 6};
  printf("expected_res: %d %d\n", expected_res.i, expected_res.j);
  printf("res: %d %d\n", res.i, res.j);
  // assert(expected_res == res);
  return 0;
}
