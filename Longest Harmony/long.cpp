class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counts;
        
        for (int num : nums) {
            counts[num]++;
        }
        
        int ans = 0;
        for (auto pair : counts) {
            int num = pair.first;
            if (counts.count(num+1) > 0) {
                int subAns = counts[num+1] + counts[num];
                ans = max(ans, subAns);
            }
        }
        
        return ans;
    }
};