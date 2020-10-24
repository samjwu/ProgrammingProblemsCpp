class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        vector<int> minArr;
        minArr.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            minArr.push_back(min(nums[i], minArr[i-1]));
        }
        for (int j=nums.size()-1; j>=0; j--) {
            if (nums[j] > minArr[j]) {
                while (!stk.empty() && stk.top() <= minArr[j]) {
                    stk.pop();
                }
                if (!stk.empty() && stk.top() < nums[j]) {
                    return true;
                }
                stk.push(nums[j]);
            }
        }
        return false;
    }
};