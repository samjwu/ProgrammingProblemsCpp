class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        
        int start = nums.size();
        int end = 0;
        
        for (int i=0; i<nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                start = min(start, stk.top());
                stk.pop();
            }
            
            stk.push(i);
        }
        
        while (!stk.empty()) {
            stk.pop();
        }
        
        for (int i=nums.size()-1; i>=0; i--) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                end = max(end, stk.top());
                stk.pop();
            }
            
            stk.push(i);
        }
        
        if (end - start > 0) {
            return end - start + 1;
        }
        
        return 0;
    }
};