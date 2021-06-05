class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = pow(10, 9) + 7;
        
        vector<pair<int, int>> candidates;
        for (int i=0; i<n; i++) {
            candidates.push_back({efficiency[i], speed[i]});
        }
        sort(candidates.begin(), candidates.end(), [](pair<int, int> c1, pair<int, int> c2) {
            return c1.first > c2.first;
        });
        
        priority_queue<int, vector<int>, greater<int>> minHeapSpeed;
        
        long sumSpeeds = 0;
        long maxPerf = 0;
        for (auto c: candidates) {
            int cEff = c.first;
            int cSpe = c.second;
            
            if (minHeapSpeed.size() > k-1) {
                sumSpeeds -= minHeapSpeed.top();
                minHeapSpeed.pop();
            }
            minHeapSpeed.push(cSpe);
            
            sumSpeeds += cSpe;
            maxPerf = max(maxPerf, sumSpeeds * cEff);
        }
        
        return (int) (maxPerf % mod);
    }
};