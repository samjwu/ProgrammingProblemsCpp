class Solution {
public:
    bool dfs(vector<int>& nums, int subsetSum, int size, unordered_map<string, bool>& memo) {
        if (subsetSum == 0) {
            return true;
        }
        
        if (subsetSum < 0 || size == 0) {
            return false;
        }
        
        string key = to_string(size) + "-" + to_string(subsetSum);
        if (memo[key] != 0) {
            return (memo[key] == true);
        }
        bool ans = dfs(nums, subsetSum - nums[size-1], size - 1, memo) || dfs(nums, subsetSum, size - 1, memo);
        memo[key] = ans;
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num:nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int subsetSum = sum / 2;
        int size = nums.size();
        unordered_map<string, bool> memo;
        return dfs(nums, subsetSum, size - 1, memo);
    }
};