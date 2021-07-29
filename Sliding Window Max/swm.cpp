class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        
        deque<int> window;
        vector<int> ans;
        int n = nums.size();
        
        for (int idx = 0; idx < n; idx++) {
            while (!window.empty() && idx - window.front() >= k) {
                window.pop_front();
            }
            
            while (!window.empty() && nums[window.back()] < nums[idx]) {
                window.pop_back();
            }
            
            window.push_back(idx);
            
            if (idx >= k - 1) {
                ans.push_back(nums[window.front()]);
            }
        }
        
        return ans;
    }
};