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
        vector<vector<bool>> memo(size + 1, vector<bool>(subsetSum + 1, false));
        memo[0][0] = true;
        for (int i = 1; i<= size; i++) {
            int curr = nums[i-1];
            for (int j = 0; j <= subsetSum; j++) {
                if (j < curr) {
                    memo[i][j] = memo[i-1][j];
                } else {
                    memo[i][j] = (memo[i-1][j] || memo[i-1][j-curr]);
                }
            }
        }
        
        return memo[size][subsetSum];
    }
};