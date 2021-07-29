class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        int searchIdx;
        int start = 0;
        int n = products.size();
        string prefix;
        
        for (char c: searchWord) {
            prefix.push_back(c);
            
            searchIdx = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            
            vector<string> subans;
            for (int i=searchIdx; i<min(searchIdx+3, n) && products[i].compare(0, prefix.length(), prefix)==0; i++) {
                subans.push_back(products[i]);
            }
            ans.push_back(subans);
            
            start = searchIdx;
        }
        
        return ans;
    }
};