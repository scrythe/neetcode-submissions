#ifndef unity
#include <stdint.h>
#include <string>
#include <vector>
using std::string;
using std::vector;
#endif

#ifdef BUILD_DEBUG
#define assert(val)                                                            \
  if (!(val)) {                                                                \
    __builtin_trap();                                                          \
  }
#else
#define assert(val) (void)(val)
#endif

typedef uint8_t u8;
typedef uint16_t u16;

#include <string.h>

#define MAX_AMOUNTS_STRINGS 10000
#define MAX_AMOUNTS_STRING 1000
#define HASHMAP_CAPACITY (3 * MAX_AMOUNTS_STRINGS)

typedef u8 LetterFrequency[26];

inline vector<vector<string>> groupAnagrams_inline(vector<string> &strs) {
  u16 letter_frequency_hashmap[HASHMAP_CAPACITY + 1] = {};
  u16 letter_frequency_hashmap_length = 0;
  LetterFrequency letter_frequency_total_list[MAX_AMOUNTS_STRINGS + 1] = {};
  u16 hashed_keys[MAX_AMOUNTS_STRINGS + 1] = {};
  vector<vector<string>> letter_frequency_anagrams_total_list =
      vector<vector<string>>(MAX_AMOUNTS_STRINGS + 1);

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
    u16 letter_frequency_bucket_key =
        letter_frequency_hashed_key % HASHMAP_CAPACITY +
        1; // 0 value means no element

    u16 letter_frequency_hashmap_value =
        letter_frequency_hashmap[letter_frequency_bucket_key];

    while (true) {
      if (letter_frequency_hashmap_value == 0) {
        letter_frequency_hashmap_length += 1;
        letter_frequency_hashmap[letter_frequency_bucket_key] =
            letter_frequency_hashmap_length;
        assert(letter_frequency_hashmap_length <= MAX_AMOUNTS_STRINGS);
        letter_frequency_anagrams_total_list[letter_frequency_hashmap_length]
            .push_back(str);
        hashed_keys[letter_frequency_hashmap_length] =
            letter_frequency_hashed_key;
        memcpy(letter_frequency_total_list[letter_frequency_hashmap_length],
               letter_frequency_map, sizeof(LetterFrequency));
        break;
      } else if (hashed_keys[letter_frequency_hashmap_value] ==
                     letter_frequency_hashed_key &&
                 memcmp(letter_frequency_map,
                        letter_frequency_total_list
                            [letter_frequency_hashmap_value],
                        sizeof(LetterFrequency)) == 0) {
        assert(letter_frequency_hashmap_value <= MAX_AMOUNTS_STRINGS);
        letter_frequency_anagrams_total_list[letter_frequency_hashmap_value]
            .push_back(str);
        break;
      } else {
        letter_frequency_bucket_key =
            letter_frequency_bucket_key % HASHMAP_CAPACITY + 1;
        letter_frequency_hashmap_value =
            letter_frequency_hashmap[letter_frequency_bucket_key];
      }
    }
  }
  return vector<vector<string>>(letter_frequency_anagrams_total_list.begin() +
                                    1,
                                letter_frequency_anagrams_total_list.begin() +
                                    1 + letter_frequency_hashmap_length);
}

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    return groupAnagrams_inline(strs);
  }
};
