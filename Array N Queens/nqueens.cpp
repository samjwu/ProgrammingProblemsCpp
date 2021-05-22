class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        sz = n;
        string squares(n, '.');
        vector<string> board(n, squares);
        backtrack(0, board, unordered_set<int>(), unordered_set<int>(), unordered_set<int>());
        return ans;
    }
    
private:
    int sz;
    vector<vector<string>> ans;
    
    void backtrack(int row, vector<string> board, unordered_set<int> fullCol, unordered_set<int> fullForwardDiag, unordered_set<int> fullBackDiag) {
        if (row == sz) {
            ans.push_back(board);
            return;
        }
        
        for (int col=0; col<sz; col++) {
            int forwardDiag = row - col;
            int backDiag = row + col;
            
            if (fullCol.count(col) > 0 || fullForwardDiag.count(forwardDiag) > 0 || fullBackDiag.count(backDiag) > 0) {
                continue;
            }
            
            fullCol.insert(col);
            fullForwardDiag.insert(forwardDiag);
            fullBackDiag.insert(backDiag);
            board[row][col] = 'Q';
            
            backtrack(row+1, board, fullCol, fullForwardDiag, fullBackDiag);
            
            fullCol.erase(col);
            fullForwardDiag.erase(forwardDiag);
            fullBackDiag.erase(backDiag);
            board[row][col] = '.';
        }
    }
};