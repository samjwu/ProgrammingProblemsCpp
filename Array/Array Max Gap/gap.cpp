class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> set;
        int prev = -1;
        
        for (int num: nums) {
            set.insert(num);
        }
        
        int ans = 0;
        for (int num: set) {
            if (prev > 0) {
                ans = max(ans, num - prev);
            }
            prev = num;
        }
        
        return ans;
    }
};