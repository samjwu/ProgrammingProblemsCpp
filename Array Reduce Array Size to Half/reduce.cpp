class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0;
        int count = 0;
        int n = arr.size();
        int half = (n+1) / 2;
        map<int, int> freqMap;
        vector<pair<int, int>> freq;
        
        for (int i: arr) {
            freqMap[i]++;
        }
        
        for (auto p: freqMap) {
            freq.push_back(p);
        }
        
        sort(freq.begin(), freq.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        });
        
        for (auto p: freq) {
            ans++;
            count += p.second;
            
            if (count >= half) {
                break;
            }
        }
        
        return ans;
    }
};