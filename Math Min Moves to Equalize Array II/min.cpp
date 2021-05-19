class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int median = nums[nums.size()/2];
        for (int n: nums) {
            ans += abs(n - median);
        }
        
        return ans;
    }
};