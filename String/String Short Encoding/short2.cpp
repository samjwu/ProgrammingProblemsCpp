class Trie {
private:
    Trie* next[26] = {0};
    bool endOfWord = false;
    
public:
    Trie() {
        
    }
    
    ~Trie() {
        for (int i=0; i<26; i++) {
            delete next[i];
        }
    }
    
    int insert(string& word) {
        Trie* root = this;
        bool newBranch = false;
        
        for (char c: word) {
            if (!root->next[c-'a']) {
                newBranch = true;
                root->next[c-'a'] = new Trie;
            }
            
            root = root->next[c-'a'];
        }
        
        root->endOfWord = true;
        
        if (newBranch) {
            return word.size();
        }
        return 0;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string w1, string w2) -> bool {
            return w1.length() > w2.length();
        });
        
        Trie root;
        
        int ans = 0;
        
        for (string word: words) {
            reverse(word.begin(), word.end());
            
            int count = root.insert(word);
            if (count > 0) {
                ans += count + 1;
            }
        }
        
        return ans;
    }
};

