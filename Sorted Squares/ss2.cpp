class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start = 0;
        int end = nums.size() - 1;
        
        for (int idx = nums.size() - 1; idx >= 0; idx--) {
            if (abs(nums[start]) > abs(nums[end])) {
                ans[idx] = nums[start] * nums[start];
                start++;
            } else {
                ans[idx] = nums[end] * nums[end];
                end--;
            }
        }
        
        return ans;
    }
};