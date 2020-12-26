class Solution {
public:
    void getUpDiagonal(vector<vector<int>>& matrix, vector<int>& ans, int i, int j, int m) {
        vector<int> ansRev;
        while (i <= m && j >= 0) {
            ansRev.push_back(matrix[i][j]);
            i++;
            j--;
        }
        
        for (int k = ansRev.size() - 1; k >= 0; k--) {
            ans.push_back(ansRev[k]);
        }
    }
    
    void getDownDiagonal(vector<vector<int>>& matrix, vector<int>& ans, int i, int j, int m) {
        while (i <= m && j >= 0) {
            ans.push_back(matrix[i][j]);
            i++;
            j--;
        }
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return ans;
        }
        
        int i = 0;
        int j = 0;
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        bool upDirection = true;
        
        while (i <= m) {
            if (upDirection) {
                getUpDiagonal(matrix, ans, i, j, m);
                upDirection = false;
            } else {
                getDownDiagonal(matrix, ans, i, j, m);
                upDirection = true;
            }
            
            if (j < n) {
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};