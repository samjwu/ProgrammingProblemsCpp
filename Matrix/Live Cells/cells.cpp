class Solution {
public:
    int calcCell(vector<vector<int>>& board, int i, int j, int m, int n) {
        int liveNeighbors = 0;
        
        for (int k = max(i-1, 0); k < min(i+2, m); k++) {
            for (int l = max(j-1, 0); l < min(j+2, n); l++) {
                liveNeighbors += board[k][l];
            }
        }
        liveNeighbors -= board[i][j];
        
        if (liveNeighbors < 2 || liveNeighbors > 3) {
            return 0;
        }
        if (liveNeighbors == 3) {
            return 1;
        }
        return board[i][j];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = calcCell(board, i, j, m, n);
            }
        }
        
        board = ans;
    }
};