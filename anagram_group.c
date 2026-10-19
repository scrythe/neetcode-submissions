#define MAX_AMOUNTS_STRINGS 1000
#define HASHMAP_CAPACITY 3 * MAX_AMOUNTS_STRINGS

typedef u8 LetterFrequency[26];
typedef struct {
  LetterFrequency ptr[MAX_AMOUNTS_STRINGS];
  u16 length;
} LetterFrequencyTotalListSlice;

void groupAnagrams(slice_string strs, slice_slice_string res) {
  u8 letter_frequency_hashmap[HASHMAP_CAPACITY + 1] = {};
  return;
}
