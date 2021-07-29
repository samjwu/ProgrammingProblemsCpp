class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        
        for (int num : nums) {
            count[num]++;
        }
        
        int ans = 0;
        for (auto it = count.begin(); it != count.end(); it++) {
            int num = it->first;
            int freq = it->second;
            if (k - num == num) {
                ans += freq / 2;
            } else if (count.count(k - num) > 0) {
                int pairs = min(freq, count[k - num]);
                ans += pairs;
                count[k - num] -= pairs;
                count[num] -= pairs;
            }
        }
        
        return ans;
    }
};