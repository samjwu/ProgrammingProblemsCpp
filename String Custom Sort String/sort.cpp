class Solution {
public:
    string customSortString(string order, string str) {
        for (int i=0; i<26; i++) {
            orderMap['a' + i] = 26;
        }
        
        for (int i=0; i<order.length(); i++) {
            orderMap[order[i]] = i;
        }
        
        sort(str.begin(), str.end(), compOrder);
        
        return str;
    }
             
private:
    static map<char, int> orderMap;
    
    static bool compOrder (const char &c1, const char &c2) {
        return orderMap[c1] < orderMap[c2];
    }
};

map<char, int> Solution::orderMap; 