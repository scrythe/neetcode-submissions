#include <cstring>

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = vector<int>(2*nums.size());
        memcpy(res.data(), nums.data(), nums.size()*sizeof(int));
        memcpy(res.data()+nums.size(), nums.data(), nums.size()*sizeof(int));
        return res;
    }
};