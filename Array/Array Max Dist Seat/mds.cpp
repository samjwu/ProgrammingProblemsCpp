class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        vector<int> distForward(len, INT_MAX);
        vector<int> distBackward(len, INT_MAX);
        
        int dist = INT_MIN;
        for (int i=0; i<len; i++) {
            if (seats[i] == 1) {
                dist = 0;
            }
            if (dist >= 0) {
                distForward[i] = dist;
            }
            dist++;
        }
        
        dist = INT_MIN;
        for (int i=len-1; i>=0; i--) {
            if (seats[i] == 1) {
                dist = 0;
            }
            if (dist >= 0) {
                distBackward[i] = dist;
            }
            dist++;
        }
        
        vector<int> dists(len , 0);
        for (int i=0; i<len; i++) {
            dists[i] = min(distForward[i], distBackward[i]);
        }
        
        return *max_element(dists.begin(), dists.end());
    }
};