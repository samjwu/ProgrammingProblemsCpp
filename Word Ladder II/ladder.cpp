class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<vector<string>> q;
        q.push({beginWord});
        
        while (!q.empty()) {
            int n = q.size();
            
            for (int i=0; i<n; i++) {
                vector<string> currPath = q.front();
                q.pop();
                
                string last = currPath.back();
                
                for (int j=0; j<last.length(); j++) {
                    string temp = last;
                    
                    for (char c='a'; c<='z'; c++) {
                        temp[j] = c;
                        
                        if (wordSet.find(temp) != wordSet.end()) {
                            vector<string> newPath = currPath;
                            newPath.push_back(temp);
                            visited.insert(temp);
                            
                            if (temp == endWord) {
                                ans.push_back(newPath);
                            } else {
                                q.push(newPath);
                            }
                        }
                    }
                }
            }
            
            for (auto& word: visited) {
                wordSet.erase(word);
            }
        }
        
        return ans;
    }
};