class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        int sum = accumulate(stones.begin(), stones.end(), 0);
        return takeStone(stones, 0, n-1, sum);
    }
    
private:
    vector<vector<int>> memo;
    
    int takeStone(vector<int>& stones, int l, int r, int sum) {
        if (memo[l][r] != -1) {
            return memo[l][r];
        }
        
        // if 1 or less stones remaining, no points are received for taking stones
        if (l >= r) {
            return 0;
        }
        
        // player point total = (sum of stones - taken stone) - (points of other player)
        int left = (sum - stones[l]) - takeStone(stones, l+1, r, sum - stones[l]);
        int right = (sum - stones[r]) - takeStone(stones, l, r-1, sum - stones[r]);
        
        // alice will use optimal strategy, so take max difference
        memo[l][r] = max(left, right);
        return memo[l][r];
    }
};