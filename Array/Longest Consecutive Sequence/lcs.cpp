class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> numSet(nums.begin(), nums.end());
        
        int prev = INT_MIN;
        int subans = 1;
        for (int n: numSet) {
            if (prev == n-1) {
                subans++;
            } else {
                subans = 1;
            }
            ans = max(ans, subans);
            prev = n;
        }
        
        return ans;
    }
};