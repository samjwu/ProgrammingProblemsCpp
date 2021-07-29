class Solution {
public:
    unordered_set<string> exact;
    unordered_map<string, string> capital;
    unordered_map<string, string> vowelErr;
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    
    string strToLow(string word) {
        string ans;
        
        for (char c: word) {
            char cl = tolower(c);
            ans.push_back(cl);
        }
        
        return ans;
    }
    
    string removeVowels(string word) {
        string ans;
        
        for (char c: word) {
            if (vowels.count(c) > 0) {
                ans.push_back('*');
            } else {
                ans.push_back(c);
            }
        }
        
        return ans;
    }
    
    string check(string query) {
        if (exact.count(query) > 0) {
            return query;
        }
        
        string low = strToLow(query);
        if (capital.find(low) != capital.end()) {
            return capital[low];
        }
        
        string wrongVowel = removeVowels(low);
        if (vowelErr.find(wrongVowel) != vowelErr.end()) {
            return vowelErr[wrongVowel];
        }
        
        return "";
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        
        for (string word: wordlist) {
            exact.insert(word);
            
            string low = strToLow(word);
            if (capital.find(low) == capital.end()) {
                capital[low] = word;
            }
            
            string wrongVowel = removeVowels(low);
            if (vowelErr.find(wrongVowel) == vowelErr.end()) {
                vowelErr[wrongVowel] = word;
            }
        }
        
        for (string query: queries) {
            ans.push_back(check(query));
        }
        
        return ans;
    }
};