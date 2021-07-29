class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (target == matrix[i][j]) {
                    return true;
                } else if (target < matrix[i][j]) {
                    return false;
                }
            }
        }
        return ans;
    }
};