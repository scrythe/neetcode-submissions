typedef uint8_t u8;
typedef uint16_t u16;

#include <string.h>

#define MAX_AMOUNTS_STRINGS 1000
#define HASHMAP_CAPACITY 3 * MAX_AMOUNTS_STRINGS

typedef u8 LetterFrequency[26];
typedef struct {
  LetterFrequency *ptr[MAX_AMOUNTS_STRINGS];
  u16 length;
} LetterFrequencyTotalListSlice;

inline vector<vector<string>> groupAnagrams_inline(vector<string> &strs) {
  u8 letter_frequency_hashmap[HASHMAP_CAPACITY + 1] = {};
  LetterFrequencyTotalListSlice letter_frequency_total_list_slice = {};
  // u8 all_strings_buffer[MAX_AMOUNTS_STRINGS * 100];

  // "struct of arrays"
  vector<vector<string>> letter_frequency_anagrams =
      vector<vector<string>>(MAX_AMOUNTS_STRINGS);
  u16 letter_frequency_list_i_list[MAX_AMOUNTS_STRINGS] = {};

  for (u16 i = 0; i < strs.size(); i++) {
    string str = strs[i];
    u8 letter_frequency_map[26] = {};
    for (u8 letter_i = 0; letter_i < str.length(); letter_i++) {
      u8 letter = str[letter_i] - 'a';
      letter_frequency_map[letter] += 1;
    }
    // letter_frequency_total_list_slice.ptr[i] = &letter_frequency_map;

    u16 letter_frequency_hashed_key = 0;
    for (u8 letter_i = 0; letter_i < 26; letter_i++) {
      u8 letter_frequency = letter_frequency_map[letter_i];
      letter_frequency_hashed_key =
          (letter_frequency_hashed_key * 31 + letter_frequency);
    }
    letter_frequency_hashed_key % HASHMAP_CAPACITY;
    letter_frequency_hashmap[letter_frequency_hashed_key] = i;
  }
  return {{"hm"}};
}

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    return groupAnagrams_inline(strs);
  }
};
