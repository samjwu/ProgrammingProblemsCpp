class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> ans;
        
        for (int i=1; i<n-2; i++) {
            // perform all possible splittings and get all valid numbers from the splits
            vector<string> lefts = formatCoords(s.substr(1, i));
            vector<string> rights = formatCoords(s.substr(i+1, n-2-i));
            
            // match up all valid numbers from splits
            for (string& left: lefts) {
                for (string& right: rights) {
                    ans.push_back("(" + left + ", " + right + ")");
                }
            }
        }
        
        return ans;
    }
    
private:
    vector<string> formatCoords(string s) {
        int n = s.length();
        
        // empty or has leading and trailing zeroes (therefore not valid)
        if (n == 0 || n > 1 && s[0] == '0' && s[n-1] == '0') {
            return {};
        }
        
        // has leading zero (therefore decimal number beginning with zero)
        if (n > 1 && s[0] == '0') {
            return {"0." + s.substr(1)};
        }
        
        // just a single number or has trailing zeroes (therefore no decimal)
        if (n == 1 || s[n - 1] == '0') {
            return {s};
        }
        
        // return list of possible coordinates with decimals at every valid place i=[1, n-1]
        vector<string> ans = {s};
        for (int i=1; i<n; i++) {
            ans.push_back(s.substr(0, i) + '.' + s.substr(i));
        }
        
        return ans;
    }
};