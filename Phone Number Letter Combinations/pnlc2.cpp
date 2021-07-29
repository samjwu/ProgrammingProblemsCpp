class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
     
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if (digits.length() == 0) {
            return ans;
        }
        
        queue<string> q;
        q.push("");
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            if (curr.length() == digits.length()) {
                ans.push_back(curr);
            } else {
                for (char letter: map[digits[curr.length()]]) {
                    q.push(curr + letter);
                }
            }
        }
        
        return ans;
    }
};