class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;   
        if (nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        for (int i=0; i<nums.size(); i++) {
            if (i<nums.size()-1 && nums[i+1] == nums[i]+1) {
                string a = to_string(nums[i]);
                while (i<nums.size()-1 && nums[i+1] == nums[i]+1) {
                    i++;
                }
                a.append("->");
                a.append(to_string(nums[i]));
                ans.push_back(a);
                
            } else {
                ans.push_back(to_string(nums[i]));
            }
            
        }
        return ans;
    }
};