class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for (string word: words) {
            wordSet.insert(word);
        }
        
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.length() > b.length();
        });
        
        int ans = 0;
        
        for (string word: words) {
            if (word.length() <= ans) {
                break;
            }
            ans = max(ans, recurse(word));
        }
        
        return ans;
    }
    
private:
    unordered_set<string> wordSet;
    unordered_map<string, int> memo;
    
    int recurse(string word) {
        if (memo.find(word) != memo.end()) {
            return memo[word];
        }
        
        int subans = 1;
        
        for (int i=0; i<word.length(); i++) {
            string subWord = word;
            subWord.erase(subWord.begin() + i);
            if (wordSet.count(subWord)) {
                int currSubans = recurse(subWord) + 1;
                subans = max(subans, currSubans);
            }
        }
        
        memo[word] = subans;
        return subans;
    }
};