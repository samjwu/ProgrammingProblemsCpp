class Solution {
public:
    static bool compLen(string s1, string s2) {
        return s1.length() > s2.length();
    }
    
    static bool compLex(string s1, string s2) {
        int shortest = min(s1.length(), s2.length());
        
        for (int i=0; i<shortest; i++) {
            if (s1[i] != s2[i]) {
                return s1[i] < s2[i];
            }
        }
            
        return compLen(s1, s2);
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compLex);
        stable_sort(d.begin(), d.end(), compLen);
        
        int ptr1, ptr2;
        int len1 = s.length(), len2;
        
        for (string word: d) {
            len2 = word.length();
            ptr1 = 0;
            ptr2 = 0;
            
            while (ptr1 < len1 && ptr2 < len2) {
                if (s[ptr1] == word[ptr2]) {
                    ptr2++;
                }
                ptr1++;
            }
            
            if (ptr2 == len2) {
                return word;
            }
        }
        
        return "";
    }
};