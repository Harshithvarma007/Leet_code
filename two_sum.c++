#include <vector>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> hashmap;

public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            if (hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i};
            }
            hashmap[num] = i;
        }

        return {}; // Empty vector if no valid pair is found
    }
};
