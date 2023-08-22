class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        vector<int> leftproduct(n, 1);
        vector<int> rightproduct(n, 1);

        int mul = 1;
        for (int i = 0; i < n; i++) {
            leftproduct[i] = mul;
            mul *= nums[i];
        }

        mul = 1;
        for (int i = n - 1; i >= 0; i--) {
            rightproduct[i] = mul;
            mul *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            result[i] = leftproduct[i] * rightproduct[i];
        }

        return result;
    }
};
