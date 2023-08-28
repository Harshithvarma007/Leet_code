class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            maxArea = max(maxArea, area);
            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return maxArea;
    }
};
