class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int currSum = 0, maxSum = 0;
        set<int> set;
        
        while (i < n && j < n) {
            if (set.count(nums[j]) == 0) {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
                set.insert(nums[j]);
                j++;
            } else {
                currSum = currSum - nums[i];
                set.erase(nums[i]);
                i++;
            }
        }
        
        return maxSum;
    }
};