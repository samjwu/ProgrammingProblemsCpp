class Solution {
public:
    string intToRoman(int num) {
        string ans;
        
        map<int, string> map = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        
        while (num > 0) {
            for (auto riter = map.rbegin(); riter != map.rend(); riter++) {
                if (riter->first <= num) {
                    ans.append(riter->second);
                    num -= riter->first;
                    break;
                }
            }
        }
        
        return ans;
    }
};