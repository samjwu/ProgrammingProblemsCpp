class Solution {
public:
    int n;
    vector<int> memo;
    
    int dp(vector<int>& nums, int remainder) {
        if (memo[remainder] != -1) {
            return memo[remainder];
        }
        
        int subans = 0;
        
        for (int i=0; i<n; i++) {
            if (remainder - nums[i] >= 0) {
                subans += dp(nums, remainder - nums[i]);
            }
        }
        
        memo[remainder] = subans;
        return memo[remainder];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        
        memo = vector<int>(target+1, -1);
        memo[0] = 1;
        
        return dp(nums, target);
    }
};