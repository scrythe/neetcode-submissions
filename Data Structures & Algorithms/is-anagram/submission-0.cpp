#include <string.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef uint16_t u16;

// max frequency is max length of string (string with max length that has sam
// letter) max string length (5*10^4) fits in 16 bits

class Solution {
public:
  bool isAnagram(string s, string t) {
    u16 letter_frequency_map_s[26] = {};
    u16 letter_frequency_map_t[26] = {};

    for (u16 i = 0; i < s.length(); i++) {
      u8 letter = s[i] - 'a';
      letter_frequency_map_s[letter] += 1;
    }
    for (u16 i = 0; i < t.length(); i++) {
      u8 letter = t[i] - 'a';
      letter_frequency_map_t[letter] += 1;
    }

    return memcmp(letter_frequency_map_s, letter_frequency_map_t,
                  sizeof(letter_frequency_map_s)) == 0;
  }
};