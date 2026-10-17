typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t i32;

#ifdef BUILD_DEBUG
#define assert(val)                                                            \
  do {                                                                         \
    if (!(val)) {                                                              \
      __builtin_trap();                                                        \
    }                                                                          \
  } while (0)
#else
#define assert(val) (void)(val)
#endif

#define MAX_LENGTH 1000
const int MAX_HASHED_NUMBER = 2e7 + 2; // -10.000.000 to 10.000.000, +2 because
// 0 should not be a value (for hashset)

typedef struct {
  u32 key;
  u16 value;
  u16 next_node;
} HashMapEntry;

typedef struct {
  u16 i;
  u16 j;
} Res;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {

    // extra nodes happen after MAX_LENGTH (after half), makes logic/ iterarting
    // easiser since I don't need to differentiate between two arrays
    HashMapEntry nums_hashmap[2 * MAX_LENGTH] = {};
    u16 hashmap_len = MAX_LENGTH;

    for (u16 i = 0; i < nums.size(); i++) {
      i32 num_i = nums[i];
      i32 num_j = target - num_i;
      u32 hashed_num_j =
          num_j + 1e7 + 1; // +1 because it should not be 0, used for hashmap
      assert(hashed_num_j != 0);
      // +1 because first element not valid
      u16 hashmap_num_j_index = hashed_num_j % MAX_LENGTH + 1;
      assert(hashmap_num_j_index != 0);
      HashMapEntry j_entry = nums_hashmap[hashmap_num_j_index];
      while (j_entry.key != hashed_num_j && j_entry.next_node != 0) {
        j_entry = nums_hashmap[j_entry.next_node];
      }
      if (j_entry.key == hashed_num_j) {
        u16 j = j_entry.value;
        vector<int> res = {
            i < j ? i : j,
            i < j ? j : i,
        };
        return res;
      } else {
        u32 hashed_num_i = num_i + 1e7 + 1;
        assert(hashed_num_i != 0);
        u16 hashmap_num_i_index = hashed_num_i % MAX_LENGTH + 1;
        assert(hashmap_num_i_index != 0);
        HashMapEntry *i_entry = &nums_hashmap[hashmap_num_i_index];
        if (i_entry->key == 0) {
          *i_entry = (HashMapEntry){
              .key = hashed_num_i,
              .value = i,
          };
        } else {
          while (i_entry->next_node != 0) {
            i_entry = &nums_hashmap[i_entry->next_node];
          }
          hashmap_len += 1;
          i_entry->next_node = hashmap_len;
          nums_hashmap[hashmap_len] = (HashMapEntry){
              .key = hashed_num_i,
              .value = i,
          };
        }
      }
    }

    vector<int> should_not_happen;
    assert(false);
    return should_not_happen;
  }
};