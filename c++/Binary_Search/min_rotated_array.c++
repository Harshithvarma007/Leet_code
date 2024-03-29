class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left++;
            }
        }

        return nums[left];
    }
};
