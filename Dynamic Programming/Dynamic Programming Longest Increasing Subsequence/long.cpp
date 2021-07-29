class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i=0; i<n; i++) {
            auto iter = lower_bound(ans.begin(), ans.end(), nums[i]);
            
            if (iter == ans.end()) {
                ans.push_back(nums[i]);
            } else {
                *iter = nums[i];
            }
        }
        
        return ans.size();
    }
};