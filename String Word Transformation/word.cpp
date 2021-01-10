class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        set<string> wordSet;
        for (string word : wordList) {
            wordSet.insert(word);
        }
        
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        
        while (!q.empty()) {
            ans++;
            
            int neighbors = q.size();
            while (neighbors > 0) {
                neighbors--;
                string currentWord = q.front();
                q.pop();
                
                for (int i = 0; i < currentWord.length(); i++) {
                    string tempWord = currentWord;
                    for (char c = 'a'; c <= 'z'; c++) {
                        tempWord[i] = c;
                        if (tempWord == currentWord) {
                            continue;
                        }
                        if (tempWord == endWord) {
                            return ans + 1;
                        }
                        if (wordSet.find(tempWord) != wordSet.end()) {
                            q.push(tempWord);
                            wordSet.erase(tempWord);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};