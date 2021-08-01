class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows*cols-1;
        bool ans = false;
        int i, j, mid;
        while (left <= right) {
            mid = (right+left)/2;
            i = mid / cols;
            j = mid % cols;
            if (target < matrix[i][j]) {
                right = mid - 1;
            } else if (target == matrix[i][j]) {
                return true;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};