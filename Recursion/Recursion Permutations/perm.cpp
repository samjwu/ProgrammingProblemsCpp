class Solution {
public:
    void addPerms(vector<int>& nums, vector<int>& ans, map<int, int>& available, vector<vector<int>>& finans) {
        if (ans.size() == nums.size()) {
            finans.push_back(ans);
            return;
        }
        for (auto pair:available) {
            if (pair.second == 0) {
                continue;
            }
            ans.push_back(pair.first);
            available[pair.first]--;
            addPerms(nums, ans, available, finans);
            ans.pop_back();
            available[pair.first]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        map<int, int> available;
        for (int num:nums) {
            available[num]++;
        }
        vector<vector<int>> finans;
        addPerms(nums, ans, available, finans);
        return finans;
    }
};