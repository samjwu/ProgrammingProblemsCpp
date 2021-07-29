class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int numsFiltered[nums.size() + 2];
        
        int idx = 1;
        for (int num : nums) {
            if (num > 0) {
                numsFiltered[idx] = num;
                idx++;
            }
        }
        
        numsFiltered[0] = 1;
        numsFiltered[idx] = 1;
        idx++;
        
        vector<vector<int>> memo(idx, vector<int>(idx, 0));
        for (int i = 2; i < idx; i++) {
            for (int l = 0; l < idx - i; l++) {
                int r = l + i;
                
                for (int j = l + 1; j < r; j++) {
                    memo[l][r] = max(memo[l][r], numsFiltered[l] * numsFiltered[j] * numsFiltered[r] + memo[l][j] + memo[j][r]);
                }
            }
        }
        
        return memo[0][idx - 1];
    }
};