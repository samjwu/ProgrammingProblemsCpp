class Solution {
public:
    int rob_helper(vector<int>& nums, int idx, int *memo) {
        if (idx < 0) {
            return 0;
        }
        if (memo[idx] >= 0) {
            return memo[idx];
        }
        int ans = max(rob_helper(nums, idx-2, memo) + nums[idx],\
                   rob_helper(nums, idx-1, memo));
        memo[idx] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int memo[nums.size()];
        for (int i=0; i<nums.size(); i++) {
            memo[i] = -1;
        }
        return rob_helper(nums, nums.size()-1, memo);
    }
};