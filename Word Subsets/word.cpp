class Solution {
public:
    vector<int> getFreq(string s) {
        vector<int> freq(26, 0);
        
        for (char c: s) {
            freq[c-'a']++;
        }
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        vector<int> fullb(26, 0);
        
        for (string bs: B) {
            vector<int> freqbs = getFreq(bs);
            for (int i=0; i<26; i++) {
                fullb[i] = max(fullb[i], freqbs[i]);
            }
        }
        
        for (string as: A) {
            vector<int> freqas = getFreq(as);
            bool valid = true;
            for (int i=0; i<26; i++) {
                if (freqas[i] < fullb[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(as);
            }
        }
        
        return ans;
    }
};