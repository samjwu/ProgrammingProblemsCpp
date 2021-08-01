class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long ik0 = 0;
        long ik1 = INT_MIN;
        
        for (int price: prices) {
            long i_1k0 = ik0;
            ik0 = max(ik0, ik1 + price - fee);
            ik1 = max(ik1, i_1k0 - price);
        }
        
        return (int) ik0;
    }
};