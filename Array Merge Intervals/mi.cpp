class Solution {
public:
    static bool comp(vector<int> i1, vector<int> i2) {
        return i1[0] < i2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        for (int i=0; i<intervals.size(); i++) {
            vector<int> v = {intervals[i][0]};
            int end = intervals[i][1];
            int skip = 0;
            for (int j=i+1; j<intervals.size(); j++) {
                if (end >= intervals[j][0]) {
                    end = max(end, intervals[j][1]);
                    skip++;
                } else {
                    break;
                }
            }
            i += skip;
            v.push_back(end);
            ans.push_back(v);
        }
        return ans;
    }
};