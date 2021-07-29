class Solution {
public:
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
        vector<bool> memo(subsetSum + 1, false);
        memo[0] = true;
        for (int curr : nums) {
            for (int j = subsetSum; j >= curr; j--) {
                memo[j] = (memo[j] || memo[j-curr]);
            }
        }
        
        return memo[subsetSum];
    }
};