class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
        }
        
        if (x > sum) {
            return -1;
        }
        
        int n = nums.size();
        int left = 0;
        int right = 0;
        int curr = 0;
        int ans = -1;
        
        while (right < n) {
            curr += nums[right];
            while (curr > sum - x && left <= right){
                curr -= nums[left];
                left++;
            }
            if (curr == sum - x) {
                ans = max(ans, right - left + 1);  
            }
            right++;
        }
        
        if (ans == -1) {
            return ans;
        }
        return n - ans;
    }
};