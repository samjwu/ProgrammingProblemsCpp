class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int l=0; l<n; l++) {
            vector<int> sums(m, 0);
            
            for (int r=l; r<n; r++) {
                for (int i=0; i<m; i++) {
                    sums[i] += matrix[i][r];
                }
                
                ans = max(ans, maxSumSubArr(sums, k));
            }
        }
        
        return ans;
    }
    
private:
    int maxSumSubArr(vector<int>& sums, int k) {
        set<int> runningSums;
        runningSums.insert(0);
        
        int currSum = 0;
        int currMax = INT_MIN;
        
        for (int sum: sums) {
            currSum += sum;
            set<int>::iterator it = runningSums.lower_bound(currSum - k);
            
            if (it != runningSums.end()) {
                currMax = max(currMax, currSum - *it);
            }
            
            runningSums.insert(currSum);
        }
        
        return currMax;
    }
};