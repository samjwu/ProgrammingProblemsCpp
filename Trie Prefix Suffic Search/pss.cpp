class Trie {
public:
    Trie() {
        children = vector<Trie*>(27, nullptr);
        index = 0;
    }
    
    ~Trie() {
        for (int i=0; i<27; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
    
    void add(vector<string>& words, int idx) {
        // note "{" is just after "z" on the ASCII table 
        string word = words[idx] + "{";
        int l = word.length();
        
        for (int i=0; i<l; i++) {
            Trie* curr = this;
            curr->index = idx;
            
            for (int j=i; j<l*2-1; j++) {
                int k = word[j%l] - 'a';
                
                if (curr->children[k] == nullptr) {
                    curr->children[k] = new Trie();
                }
                
                curr = curr->children[k];
                curr->index = idx;
            }
        }
    }
    
    int getIndex(string key) {
        Trie* curr = this;
        
        for (char letter: key) {
            if (curr->children[letter - 'a'] == nullptr) {
                return -1;
            }
            curr = curr->children[letter - 'a'];
        }
        
        return curr->index;
    }
        
private:
    vector<Trie*> children;
    int index;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        specDict = new Trie();
        int n = words.size();
        
        for (int idx=0; idx<n; idx++) {
            specDict->add(words, idx);
        }
    }
    
    int f(string prefix, string suffix) {
        // note "{" is just after "z" on the ASCII table 
        string key = suffix + "{" + prefix;
        
        return specDict->getIndex(key);
    }
    
private:
    Trie* specDict;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */