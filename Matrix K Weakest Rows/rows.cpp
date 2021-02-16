class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        
        for (int col=n-1; col>=0; col--) {
            for (int row=m-1; row>=0; row--) {
                if (mat[row][col]==1 && (col==n-1 || (mat[row][col+1]==0))) {
                    ans.push_back(row);
                }
            }
        }
        
        for (int row=m-1; row>=0; row--) {
            if (mat[row][0]==0) {
                ans.push_back(row);
            }
        }
        
        return vector<int>(ans.rbegin(), ans.rbegin()+k);
    }
};