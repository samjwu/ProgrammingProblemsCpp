class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int diff = n - k;
        
        for (int i=1; i<diff; i++) {
            ans.push_back(i);
        }
        
        for (int i=0; i<=k; i++) {
            int element = (i%2 == 0) ? (diff + i/2) : (n - i/2);
            ans.push_back(element);
        }
        
        return ans;
    }
};