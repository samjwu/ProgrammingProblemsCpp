class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [] (vector<int>& box1, vector<int>& box2) {
            return box1[1] >= box2[1];    
        });
        
        for (auto& box: boxTypes) {
            if (truckSize >= box[0]) {
                truckSize -= box[0];
                ans += box[0] * box[1];
            } else {
                ans += truckSize * box[1];
                truckSize = 0;
                break;
            }
        }
        
        return ans;
    }
};