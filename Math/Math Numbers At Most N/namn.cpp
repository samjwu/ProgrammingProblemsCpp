class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(), digits.end());
        
        int nElem = digits.size();
        string nStr = to_string(n);
        int nLen = nStr.length();
        int ans = 0;
        
        for (int i=1; i<nLen; i++) {
            ans += pow(nElem, i);
        }
        
        bool match;
        for (int i=0; i<nLen; i++) {
            match = false;
            for (string digit:digits) {
                if (digit[0] < nStr[i]) {
                    cout<<"a"<<endl;
                    ans += pow(nElem, nLen - 1 - i);
                } else if (digit[0] == nStr[i]) {
                    match = true;
                    break;
                } else {
                    break;
                }
            }
            
            if (!match) {
                return ans;
            }
        }
        
        return ans + 1;
    }
};