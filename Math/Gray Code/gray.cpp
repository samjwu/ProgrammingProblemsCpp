class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0, 1};
        
        for (int i=1; i<n; i++) {
            int sz = ans.size();
            
            for (int j=sz-1; j>=0; j--) {
                ans.push_back(ans[j] | (1 << i));
            }
        }
        
        return ans;
    }
};