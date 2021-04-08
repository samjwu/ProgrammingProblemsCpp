class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> ans;
    string phoneNum;
    
    void backtrack(int i, string path) {
        if (path.length() == phoneNum.length()) {
            ans.push_back(path);
            return;
        }
        
        string letters = map[phoneNum[i]];
        for (char letter: letters) {
            path.push_back(letter);
            backtrack(i+1, path);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return ans;
        }
        
        phoneNum = digits;
        string path;
        backtrack(0, path);
        
        return ans;
    }
};