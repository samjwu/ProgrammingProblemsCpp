class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> wordMap;
        int n = words.size();
        
        for (int i=0; i<n; i++) {
            wordMap[words[i]] = i;
        }
        
        for (int i=0; i<n; i++) {
            if (words[i] == "") {
                for (int j=0; j<n; j++) {
                    if (isPalindrome(words[j], 0, words[j].size() - 1) && i != j) {
                        ans.push_back({i, j});
                        ans.push_back({j, i});
                    }
                }
                
                continue;
            }
            
            string backwards = words[i];
            reverse(backwards.begin(), backwards.end());
            if (wordMap.find(backwards) != wordMap.end()) {
                int j = wordMap[backwards];
                if (j != i) {
                    ans.push_back({i, j});
                }
            }
            
            for (int j=1; j<backwards.size(); j++) {
                if (isPalindrome(backwards, 0, j-1)) {
                    string sub = backwards.substr(j, backwards.size() - j);
                    if (wordMap.find(sub) != wordMap.end()) {
                        ans.push_back({i, wordMap[sub]});
                    }
                }
                
                if (isPalindrome(backwards, j, backwards.size() - 1)) {
                    string sub = backwards.substr(0, j);
                    if (wordMap.find(sub) != wordMap.end()) {
                        ans.push_back({wordMap[sub], i});
                    }
                }
            }
        }
        
        return ans;
    }
    
private:
    bool isPalindrome(string& word, int i, int j) {
        while (i < j) {
            if (word[i] != word[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};