class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int sum = 0;
        int window = 0;
        for (int l=0; l<n; l++) {
            sum += cardPoints[l];
            if (l == windowSize - 1) {
               window = sum; 
            }
        }
        int ans = sum - window;
        
        int i = 0;
        int j = windowSize;
        while (j < n) {
            window -= cardPoints[i++];
            window += cardPoints[j++];
            ans = max(ans, sum - window);
        }
        
        return ans;
    }
};