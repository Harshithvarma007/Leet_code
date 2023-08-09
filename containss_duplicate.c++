class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int i : nums) {
            if (hashmap[i] > 0) {
                return true;
            }
            hashmap[i]++;
        }
        return false;
    }
};
