class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int i = 0;
        int j = numbers.size() - 1;
        vector<int> res(2); // Initialize the vector with size 2
        
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                res[0] = i + 1; // Indices are 1-based
                res[1] = j + 1;
                return res; // Return the result when the sum is equal to the target
            }
        }
        
        return res;
        
    }
};