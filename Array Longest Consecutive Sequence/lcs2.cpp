class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (int n: set) {
            if (set.count(n-1) == 0) {
                int curr = n;
                int sofar = 1;
                
                while (set.count(curr+1)) {
                    curr++;
                    sofar++;
                }
                
                ans = max(ans, sofar);
            }
        }
        
        return ans;
    }
};