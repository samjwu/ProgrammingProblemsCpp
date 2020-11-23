class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {
            ".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...","-","..-",
            "...-",".--","-..-","-.--","--.."
        };
        
        set<string> wordset;
        
        for (string word:words) {
            string codeword;
            for (char c:word) {
                codeword.append(codes[c-'a']);
            }
            wordset.insert(codeword);
        }
        
        return wordset.size();
    }
};