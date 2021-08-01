class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> freq;
        map<int, int> nums;
        for (char c: s) {
            freq[c]++;
        }
        
        nums[0] = freq['z'];
        freq['z'] -= nums[0];
        freq['e'] -= nums[0];
        freq['r'] -= nums[0];
        freq['o'] -= nums[0];
        
        nums[2] = freq['w'];
        freq['t'] -= nums[2];
        freq['w'] -= nums[2];
        freq['o'] -= nums[2];
        
        nums[4] = freq['u'];
        freq['f'] -= nums[4];
        freq['o'] -= nums[4];
        freq['u'] -= nums[4];
        freq['r'] -= nums[4];
        
        nums[6] = freq['x'];
        freq['s'] -= nums[6];
        freq['i'] -= nums[6];
        freq['x'] -= nums[6];
        
        nums[8] = freq['g'];
        freq['e'] -= nums[8];
        freq['i'] -= nums[8];
        freq['g'] -= nums[8];
        freq['h'] -= nums[8];
        freq['t'] -= nums[8];
        
        nums[1] = freq['o'];
        freq['o'] -= nums[1];
        freq['n'] -= nums[1];
        freq['e'] -= nums[1];
        
        nums[3] = freq['h'];
        freq['t'] -= nums[3];
        freq['h'] -= nums[3];
        freq['r'] -= nums[3];
        freq['e'] -= nums[3];
        freq['e'] -= nums[3];
        
        nums[7] = freq['s'];
        freq['s'] -= nums[7];
        freq['e'] -= nums[7];
        freq['v'] -= nums[7];
        freq['e'] -= nums[7];
        freq['n'] -= nums[7];
        
        nums[5] = freq['v'];
        freq['f'] -= nums[5];
        freq['i'] -= nums[5];
        freq['v'] -= nums[5];
        freq['e'] -= nums[5];
        
        nums[9] = freq['i'];
        freq['n'] -= nums[9];
        freq['i'] -= nums[9];
        freq['n'] -= nums[9];
        freq['e'] -= nums[9];
        
        string ans;
        for (auto p: nums) {
            string digit(p.second, '0' + p.first);
            ans.append(digit);
        }
        
        return ans;
    }
};