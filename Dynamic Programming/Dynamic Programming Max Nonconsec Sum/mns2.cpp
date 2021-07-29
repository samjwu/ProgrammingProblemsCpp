class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
           return 0;
        }
        
        int memo[nums.size()+1];
        memo[0] = 0;
        memo[1] = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            memo[i+1] = max(nums[i] + memo[i-1], memo[i]);
        }
        
        return memo[nums.size()];
    }
};