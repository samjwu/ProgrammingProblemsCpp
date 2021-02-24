class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        
        while (row < matrix.size() && col > -1) {
            int current = matrix[row][col];
            
            if (target == current) {
                return true;
            } else if (target < current) {
                col--;
            } else if (target > current) {
                row++;
            }
        }
        
        return false;
    }
};