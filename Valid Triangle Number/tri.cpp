class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            int k = i + 2;
            
            for (int j=i+1; j<n-1; j++) {
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                
                ans += k - j - 1;
            }
        }
        
        return ans;
    }
};