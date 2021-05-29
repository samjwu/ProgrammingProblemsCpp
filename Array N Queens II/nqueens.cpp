class Solution {
public:
    int totalNQueens(int n) {
        return backtrack(0, 0, n);
    }
    
private:
    set<int> colQueen, forwardDiagQueen, backDiagQueen;
    
    int backtrack(int row, int ans, int n) {
        for (int col=0; col<n; col++) {
            if (colQueen.count(col)) {
                continue;
            }
            
            int forwardDiag = row - col;
            if (forwardDiagQueen.count(forwardDiag)) {
                continue;
            }
            
            int backDiag = row + col;
            if (backDiagQueen.count(backDiag)) {
                continue;
            }
            
            if (row == n-1) {
                ans++;
            } else {
                colQueen.insert(col);
                forwardDiagQueen.insert(forwardDiag);
                backDiagQueen.insert(backDiag);
                
                ans = backtrack(row+1, ans, n);
                
                colQueen.erase(col);
                forwardDiagQueen.erase(forwardDiag);
                backDiagQueen.erase(backDiag);
            }
        }
        
        return ans;
    }
};