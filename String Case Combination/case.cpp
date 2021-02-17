class Solution {
public:
    void recurse(vector<string>& ans, string S, string curr, int pos) {
        if (pos == S.length()) {
            ans.push_back(curr);
            return;
        }
        
        if (isdigit(S[pos])) {
            curr.push_back(S[pos]);
            recurse(ans, S, curr, pos+1);
        } else {
            string perm1 = curr;
            perm1.push_back(tolower(S[pos]));
            recurse(ans, S, perm1, pos+1);
            
            string perm2 = curr;
            perm2.push_back(toupper(S[pos]));
            recurse(ans, S, perm2, pos+1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        recurse(ans, S, "", 0);
        return ans;    
    }
};