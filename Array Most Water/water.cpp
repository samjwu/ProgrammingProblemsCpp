class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            int lowestHeight = min(height[left], height[right]);
            ans = max(ans, (right - left) * lowestHeight);
            
            while (height[left] <= lowestHeight && left < right) {
                left++;
            }
            
            while (height[right] <= lowestHeight && left < right) {
                right--;
            }
        }
        
        return ans;
    }
};