class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        for (int i=0; i<n; i++) {
            if (i > 0 && ratings[i-1] < ratings[i] && i < n-1 && ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i-1] + 1, candies[i+1] + 1);
            } else if (i > 0 && ratings[i-1] < ratings[i]) {
                candies[i] = candies[i-1] + 1;
            } else if (i < n-1 && ratings[i] > ratings[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }
        
        for (int i=n-1; i>=0; i--) {
            if (i > 0 && ratings[i-1] < ratings[i] && i < n-1 && ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i-1] + 1, candies[i+1] + 1);
            } else if (i > 0 && ratings[i-1] < ratings[i]) {
                candies[i] = candies[i-1] + 1;
            } else if (i < n-1 && ratings[i] > ratings[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};