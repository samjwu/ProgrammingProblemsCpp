class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int end = 0;
        int newi = 0;
        
        for (int i=0; i<nums.size()-1; i++) {
            newi = max(newi, i + nums[i]);
            if (i == end) {
                ans++;
                end = newi;
            }
        }
        
        return ans;
    }
};