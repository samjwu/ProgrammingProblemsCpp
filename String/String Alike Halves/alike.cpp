class Solution {
public:
    set<char> vowels = {
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    };
    
    bool halvesAreAlike(string s) {
        int half = s.length() / 2;
        string a = s.substr(0, half);
        string b = s.substr(half);
        int vowelsA = 0;
        int vowelsB = 0;
        
        for (char c: a) {
            if (vowels.count(c) > 0) {
                vowelsA++;
            }
        }
        for (char c: b) {
            if (vowels.count(c) > 0) {
                vowelsB++;
            }
        }
        
        return vowelsA == vowelsB;
    }
};