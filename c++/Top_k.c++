class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hashmap;
        
        for (auto i : nums) {
            hashmap[i]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto i : hashmap) {
            int fre = i.second;
            int num = i.first;
            bucket[fre].push_back(num);
        }

        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }
        return result;
    }
};
