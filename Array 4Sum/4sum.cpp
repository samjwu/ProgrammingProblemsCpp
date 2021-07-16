class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if (nums.size() <= 3) {
            return ans;
        }
        
        sort(begin(nums), end(nums));
        
        for (int i=0; i<nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j=i+1; j<nums.size()-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                int k = j+1;
                int l = nums.size()-1;
                
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k+1]) {
                            k++;
                        }
                        k++;
                        while (k < l && nums[l] == nums[l-1]) {
                            l--;
                        }
                        l--;
                    } else if (sum > target) {
                        while (k < l && nums[l] == nums[l-1]) {
                            l--;
                        }
                        l--;
                    } else {
                        while (k < l && nums[k] == nums[k+1]) {
                            k++;
                        }
                        k++;
                    }
                }
            }
        }
        
        return ans;
    }
};