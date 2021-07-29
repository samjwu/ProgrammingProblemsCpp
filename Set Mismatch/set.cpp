class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> numSet;
        vector<int> ans;
        
        for (int n: nums) {
            if (numSet.count(n) == 1) {
                ans.push_back(n);
            }
            numSet.insert(n);
        }
        
        for (int i=1; i<=nums.size(); i++) {
            if (numSet.count(i) == 0) {
                ans.push_back(i);
                break;
            }
        }
        
        return ans;
    }
};