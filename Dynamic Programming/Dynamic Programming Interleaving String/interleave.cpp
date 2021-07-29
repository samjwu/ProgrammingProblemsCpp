class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        
        if (m+n != s3.length()) {
            return false;
        }
        
        memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return interleave(s1, s2, s3, 0, 0, 0);    
    }
    
private:
    int m, n;
    vector<vector<int>> memo;
    
    bool interleave(string s1, string s2, string s3, int i, int j, int k) {
        if (memo[i][j] == 1) {
            return true;
        } else if (memo[i][j] == 0) {
            return false;
        }
        
        bool ans = false;
        
        if (k == s3.length()) {
            ans = true;
        }
        
        if (i < s1.length() && j < s2.length() && s1[i] == s3[k] && s2[j] == s3[k]) {
            ans = interleave(s1, s2, s3, i+1, j, k+1) || interleave(s1, s2, s3, i, j+1, k+1);
        } else if (i < s1.length() && s1[i] == s3[k]) {
            ans = interleave(s1, s2, s3, i+1, j, k+1);
        } else if (j < s2.length() && s2[j] == s3[k]) {
            ans = interleave(s1, s2, s3, i, j+1, k+1);
        }
        
        if (ans == true) {
            memo[i][j] = 1;
        } else {
            memo[i][j] = 0;
        }
        
        return ans;
    }
};